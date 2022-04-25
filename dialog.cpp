#include "dialog.h"
#include "ui_dialog.h"

//
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    sx();
    state_ct=state_fan=state_kt=false;
    state_tv=state_dvd=state_wl=false;
    mode = startTimer(1000);
    ui->stackedWidget->setCurrentIndex(0);
    ui->maichong_draw->installEventFilter(this);
    maichong_int = startTimer(1000);
    zj_int=0;
    list_cgq1.append("电视");
    list_cgq1.append("空调");
    list_cgq1.append("DVD");
    list_cgq1.append("风扇");
    list_cgq1.append("报警灯");
    list_cgq1.append("门禁");

    qj_int=0;

    ui->cgq_draw->installEventFilter(this);

    for (int i = 0; i < 6; ++i) {
        temp_list.push_back(0);
        hum_list.push_back(0);
        ill_list.push_back(0);
        co_list.push_back(0);
        ap_list.push_back(0);
        pm_list.push_back(0);

    }

    list.push_back(&temp_list);
    list.push_back(&hum_list);
    list.push_back(&ill_list);
    list.push_back(&co_list);
    list.push_back(&ap_list);
    list.push_back(&pm_list);

    list_cgq.append("温度");
    list_cgq.append("湿度");
    list_cgq.append("光照");
    list_cgq.append("二氧化碳");
    list_cgq.append("气压");
    list_cgq.append("PM2.5");

    yya=0;

    ui->widget->hide();
    ui->drawname->hide();

    time_i=0;
    time_i2=0;
    time_i_time = startTimer(1000*60);
    time_i_time2 = startTimer(1000*60);

    thread_zj=new Thread_zj();
    connect(thread_zj,SIGNAL(control(QString,int)),this,SLOT(control(QString,int)));

    ui->select_ml->clear();
    zj_time_time = startTimer(5000);

    ui->qj->setEnabled(false);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::timerEvent(QTimerEvent *e)
{
    if (e->timerId()==time) {
        static int i=0,k=0;
        i++;
        if (k==0) {
            if (i<=MAX_BOARDID_NUM) {
                uint sz[3];
                sz[0]=0;
                sz[1]=0;
                sz[2]=i;
                ser->Send(handle->sendingDataHandle(READNODE,0,sz,3));
            }
            else {
                 i=0;
                 k++;
            }
        }
        else {
            if (i<=MAX_BOARDID_NUM) {
                uint sz[2];
                sz[0]=0;
                sz[1]=0;
                ser->Send(handle->sendingDataHandle(GETSTATE,i,sz,2));
            }
            else {
                 i=k=0;
                 killTimer(time);
            }
        }
    }
    if (e->timerId()==mode) {
        if (ui->gas_int->text()!="") {
            if (ui->gas->text().toFloat()>ui->gas_int->text().toFloat()) {
                if (state_fan==false) {
                    Send(19,RELAY_SERVE,SWITCH_ON,VOL_RELAY,CHANNEL_ALL);
                }
                if (state_wl==false) {
                    Send(20,RELAY_SERVE,SWITCH_ON,VOL_RELAY,CHANNEL_ALL);
                }
            }
        }

        for (int i = 0; i <6; ++i) {
            list.at(i)->push_back(nums[list_cgq.at(i)]);
            list.at(i)->pop_front();
            ui->cgq_draw->update();
        }

           q.exec("select *from num where mode = '"+ui->select_ml->currentText()+"'");
            if (q.next()) {
                if (q.value(4).toString()=="温度") {
                    ui->cgq->setCurrentIndex(1);
                }
                else if (q.value(4).toString()=="烟雾") {
                    ui->cgq->setCurrentIndex(2);
                }
                else if (q.value(4).toString()=="光照") {
                    ui->cgq->setCurrentIndex(3);
                }
                if (q.value(5).toString()==">") {
                    ui->tj->setCurrentIndex(1);
                }
                else if (q.value(5).toString()=="<") {
                    ui->tj->setCurrentIndex(2);
                }
                ui->zhi->setText(q.value(6).toString());
            }

        if (ui->cgq->currentIndex()==0) {
            ui->qj->setCurrentIndex(0);
        }
        else if (ui->cgq->currentIndex()==1) {
            ui->qj->setCurrentIndex(1);
        }
        else if (ui->cgq->currentIndex()==2) {
            ui->qj->setCurrentIndex(2);
        }
        else if (ui->cgq->currentIndex()==3) {
            ui->qj->setCurrentIndex(3);
        }
    }
    if (e->timerId()==maichong_int) {
        if (ui->tv->isChecked()||ui->kt->isChecked()||ui->dvd->isChecked()) {
            if (time_i2==ui->spinBox_2->text().toInt()) {

            }
            else {
                mc.push_back(0);
                if (mc.size()>60) {
                    mc.pop_front();
                }
                if (ui->spinBox_2->text().toInt()>time_i2||ui->spinBox_2->text().toInt()<time_i2) {
                        time_i2=0;
                }
            }
        }
        else {
            if (time_i2==ui->spinBox_2->text().toInt()) {

            }
            else {
                mc.push_back(1);
                if (mc.size()>60) {
                    mc.pop_front();
                }
                if (ui->spinBox_2->text().toInt()>time_i2||ui->spinBox_2->text().toInt()<time_i2) {
                        time_i2=0;
                }
            }
        }
        ui->maichong_draw->update();
    }
    if (e->timerId()==zj_time) {
        if (zj_int%2==0) {
            if (list_cgq1.at(qj_int)=="电视")
            {
                Send(numms[list_cgq1.at(qj_int)],INFRARED_SERVE,0,0,2);
                ui->textEdit->append("现在打开电视");
            }
            else if (list_cgq1.at(qj_int)=="空调")
            {
                Send(numms[list_cgq1.at(qj_int)],INFRARED_SERVE,0,0,1);
                ui->textEdit->append("现在打开空调");
            }
            else if (list_cgq1.at(qj_int)=="DVD")
            {
                Send(numms[list_cgq1.at(qj_int)],INFRARED_SERVE,0,0,3);
                ui->textEdit->append("现在打开DVD");
            }
            else {
                Send(numms[list_cgq1.at(qj_int)],RELAY_SERVE,SWITCH_ON,VOL_RELAY,CHANNEL_ALL);
                ui->textEdit->append("现在打开"+list_cgq1.at(qj_int));
            }
        }
        else {
            if (list_cgq1.at(qj_int)=="电视")
            {
                Send(numms[list_cgq1.at(qj_int)],INFRARED_SERVE,0,0,2);
                ui->textEdit->append("现在关闭电视");
            }
            else if (list_cgq1.at(qj_int)=="空调")
            {
                Send(numms[list_cgq1.at(qj_int)],INFRARED_SERVE,0,0,1);
                ui->textEdit->append("现在关闭空调");
            }
            else if (list_cgq1.at(qj_int)=="DVD")
            {
                Send(numms[list_cgq1.at(qj_int)],INFRARED_SERVE,0,0,3);
                ui->textEdit->append("现在关闭DVD");
            }
            else {
                Send(numms[list_cgq1.at(qj_int)],RELAY_SERVE,SWITCH_OFF,VOL_RELAY,CHANNEL_ALL);
                ui->textEdit->append("现在关闭"+list_cgq1.at(qj_int));
            }
            qj_int++;
        }
        zj_int++;
        if (qj_int==list_cgq1.size()) {
            killTimer(zj_time);
            zj_int=0;
            qj_int=0;
        }
    }
    if (e->timerId()==time_i_time) {
         time_i++;
         qDebug()<<time_i;
    }
    if (e->timerId()==time_i_time2) {
        time_i2++;
    }
    if (e->timerId()==zj_time_time) {
        if (ui->znmode->isChecked()) {
            qDebug()<<1;
            q.exec("select *from num");
            qDebug()<<2;
            while(q.next())
            {
                qDebug()<<3;
                QString cgq = q.value(4).toString();
                QString tj = q.value(5).toString();
                float zhi = q.value(6).toFloat();
                if (tj==">") {
                    qDebug()<<4;
                    if (nums[cgq]>zhi) {
                        if (cgq=="烟雾") {
                            if (state_fan==false) {
                                Send(20,RELAY_SERVE,SWITCH_ON,VOL_RELAY,CHANNEL_ALL);
                                ui->textEdit_2->append(q.value(1).toString()+"执行"+q.value(2).toString()+"风扇开"+"命令");
                            }
                        }
                        else if (cgq=="光照") {
                            if (state_ct==false) {
                                Send(14,RELAY_SERVE,SWITCH_ON,NODE_RELAY,CHANNEL_3);
                                ui->textEdit_2->append(q.value(1).toString()+"执行"+q.value(2).toString()+"窗帘关"+"命令");
                            }
                        }
                        else if (cgq=="温度") {
                            if (state_kt==false) {
                                Send(5,INFRARED_SERVE,0,0,1);
                                ui->textEdit_2->append(q.value(1).toString()+"执行"+q.value(2).toString()+"空调开"+"命令");
                            }
                        }
                    }
                }
                else if (tj=="<") {
                    qDebug()<<5;
                    if (nums[cgq]<zhi) {
                        qDebug()<<6;
                        if (cgq=="烟雾") {
                            if (state_fan==true) {
                                Send(20,RELAY_SERVE,SWITCH_OFF,VOL_RELAY,CHANNEL_ALL);
                                ui->textEdit_2->append(q.value(1).toString()+"执行"+q.value(2).toString()+"空调关"+"命令");
                            }
                        }
                        else if (cgq=="光照") {
                            if (state_ct==true) {
                                Send(14,RELAY_SERVE,SWITCH_ON,NODE_RELAY,CHANNEL_1);
                                ui->textEdit_2->append(q.value(1).toString()+"执行"+q.value(2).toString()+"窗帘开"+"命令");
                            }
                        }
                        else if (cgq=="温度") {
                            if (state_kt==true) {
                                Send(5,INFRARED_SERVE,0,0,1);
                                ui->textEdit_2->append(q.value(1).toString()+"执行"+q.value(2).toString()+"空调关"+"命令");
                            }
                        }
                    }
                }
                killTimer(zj_time_time);
            }
        }
    }
}

void Dialog::sx()
{
    ser = new SerialThread();
    handle = new SerialDataHandle();
    ser->handle = handle;
    connect(handle,SIGNAL(evt_deviceState(QString,QString,QString,QString)),this,SLOT(SetData(QString,QString,QString,QString)));
    if (0==ser->OnPort()) {
        time = startTimer(500);
    }

    tcp = new TcpClientThread();
    tcp->setTcpClentFlag(false);
    connect(tcp,SIGNAL(evt_socket_receive(uint,QString,uint,uint,uint)),this,SLOT(OnReceive(uint,QString,uint,uint,uint)));
    tcp->serverIP = "192.168.2.2";
    tcp->start();

    guan = new Guan();
    gp = new QButtonGroup();
    gp->setExclusive(false);
    gp->addButton(ui->wl,0);
    gp->addButton(ui->door,1);
    gp->addButton(ui->fan,2);
    gp->addButton(ui->tv,3);
    gp->addButton(ui->kt,4);
    gp->addButton(ui->dvd,5);
    connect(gp,SIGNAL(buttonClicked(int)),this,SLOT(Click(int)));

    numms["电视"]=15;
    numms["DVD"]=15;
    numms["空调"]=5;
    numms["风扇"]=20;
    numms["报警灯"]=19;
    numms["门禁"]=4;
    numms["加湿器"]=4;
    numms["窗帘"]=14;

}

void Dialog::Send(unsigned int boardId, QString type, unsigned int cmd, unsigned int cmdCode, unsigned int channel)
{
    uint Pcmd[9];
    if (type==INFRARED_SERVE) {
        if (boardId==5) {
            if (channel==1) {
                state_kt=!state_kt;
                ui->kt->setChecked(state_kt);
            }
        }
        if (boardId==15) {
            if (channel==2) {
                state_tv=!state_tv;
                ui->tv->setChecked(state_tv);
            }
            if (channel==3) {
                state_dvd=!state_dvd;
                ui->dvd->setChecked(state_dvd);
            }
        }
        handle->cmdArryHandle(Pcmd,INFRARED,channel&0xf,(channel>>8)&0xf);
    }
    if (type==DC_SERVE) {
        handle->cmdArryHandle(Pcmd,RFID,cmd,channel);
    }
    if (type==RELAY_SERVE)
    {
        if (boardId==20) {
            state_fan=cmd==SWITCH_ON?true:false;
            ui->fan->setChecked(cmd==SWITCH_ON?true:false);
        }
        if (boardId==19) {
            state_wl=cmd==SWITCH_ON?true:false;
            ui->wl->setChecked(cmd==SWITCH_ON?true:false);
        }
        handle->cmdArryHandle(Pcmd,RELAY,cmd,channel);
        if (cmdCode==NODE_RELAY) {
            handle->cmdArryHandle(Pcmd,RELAY,SWITCH_ON,channel);
            state_ct=channel==CHANNEL_1?true:false;
            ser->Send(handle->sendingDataHandle(CONTROL,boardId,Pcmd,9));
            usleep(200000);
            handle->cmdArryHandle(Pcmd,RELAY,SWITCH_OFF,CHANNEL_ALL);
            ser->Send(handle->sendingDataHandle(CONTROL,boardId,Pcmd,9));
            usleep(200000);
            ser->Send(handle->sendingDataHandle(CONTROL,boardId,Pcmd,9));
            return;
        }
    }
    ser->Send(handle->sendingDataHandle(CONTROL,boardId,Pcmd,9));
    usleep(200000);
}

void Dialog::OnReceive(unsigned int boardId, QString type, unsigned int cmd, unsigned int cmdCode, unsigned int channel)
{
    Send(boardId,type,cmd,cmdCode,channel);
}

void Dialog::SetData(const QString &boardId, const QString &type, const QString &cmd, const QString &value)
{
    if (tcp->getTcpClientFlag()) {
        tcp->upload(boardId,type,cmd,value);
    }
    if (type==TEMP_SERVE) {
        if (boardId=="2") {
            float a = value.toFloat();
            float p = (float)a/40;
            ui->temp->setValue(p*100);
            ui->ptemp->setText(value);
            int y = 280-240*p;
            ui->ptemp->move(ui->ptemp->x(),y);
            if (time_i==ui->spinBox->text().toInt()) {

            }
            else {
                nums["温度"]=value.toFloat();
                if (ui->spinBox->text().toInt()>time_i||ui->spinBox_2->text().toInt()<time_i) {
                    time_i=0;
                }
            }
        }
    }
    else if (type==HUM_SERVE) {
        if (boardId=="2") {
            float a = value.toFloat();
            float p = (float)a/60;
            ui->hum->setValue(p*100);
            ui->phum->setText(value);
            int y = 280-240*p;
            ui->phum->move(ui->phum->x(),y);
            if (time_i==ui->spinBox->text().toInt()) {

            }
            else {
                nums["湿度"]=value.toFloat();
                if (ui->spinBox->text().toInt()>time_i||ui->spinBox_2->text().toInt()<time_i) {
                    time_i=0;
                }
            }
        }
    }
    else if (type==ILL_SERVE) {
        if (boardId=="1") {
            float a = value.toFloat();
            float p =(float)a/400;
            ui->ill->setValue(p*100);
            ui->pill->setText(value);
            int y = 280-240*p;
            ui->pill->move(ui->pill->x(),y);
            if (time_i==ui->spinBox->text().toInt()) {

            }
            else {
                nums["光照"]=value.toFloat();
                if (ui->spinBox->text().toInt()>time_i||ui->spinBox_2->text().toInt()<time_i) {
                    time_i=0;
                }
            }
        }
    }
    else if (type==CO2_SERVE) {
        if (boardId=="11") {
            float a = value.toFloat();
            float p =(float)a/1000;
            ui->co2->setValue(p*100);
            ui->pco2->setText(value);
            int y = 280-240*p;
            ui->pco2->move(ui->pco2->x(),y);
            if (time_i==ui->spinBox->text().toInt()) {

            }
            else {
                nums["二氧化碳"]=value.toFloat();
                if (ui->spinBox->text().toInt()>time_i||ui->spinBox_2->text().toInt()<time_i) {
                    time_i=0;
                }
            }
        }
    }
    else if (type==AP_SERVE) {
        if (boardId=="8") {
            float a = value.toFloat();
            float p =(float)a/1200;
            ui->ap->setValue(p*100);
            ui->pap->setText(value);
            int y = 280-240*p;
            ui->pap->move(ui->pap->x(),y);
            if (time_i==ui->spinBox->text().toInt()) {

            }
            else {
                nums["气压"]=value.toFloat();
                if (ui->spinBox->text().toInt()>time_i||ui->spinBox_2->text().toInt()<time_i) {
                    time_i=0;
                }
            }
        }
    }
    else if (type==PM25_SERVE) {
        if (boardId=="12") {
            float a = value.toFloat();
            float p =(float)a/500;
            ui->pmm->setValue(p*100);
            ui->ppm->setText(value);
            int y = 280-240*p;
            ui->ppm->move(ui->ppm->x(),y);
            if (time_i==ui->spinBox->text().toInt()) {

            }
            else {
                nums["PM2.5"]=value.toFloat();
                if (ui->spinBox->text().toInt()>time_i||ui->spinBox_2->text().toInt()<time_i) {
                    time_i=0;
                }
            }
        }
    }
    else if (type==GAS_SERVE) {
        if (boardId=="16") {
            ui->gas->setText(value);
        }
    }
}

void Dialog::on_kt_push_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_save_clicked()
{
    if (ui->cgq->currentIndex()!=0 && ui->tj->currentIndex()!=0 && ui->zhi->text()!="") {
        QString dz3 = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        QString dz1= ui->cgq->currentText()+ui->tj->currentText()+ui->zhi->text();
        QString dz2 = "";
        if (ui->cgq->currentIndex()==1) {
            dz2="空调";
            dz2+=ui->tj->currentText()==">"?"开":"关";
        }
        else if (ui->cgq->currentIndex()==2) {
            dz2="风扇";
            dz2+=ui->tj->currentText()==">"?"开":"关";
        }
        else if (ui->cgq->currentIndex()==3) {
            dz2="窗帘";
            dz2+=ui->tj->currentText()==">"?"关":"开";
        }
        q.exec("select *from num where cgq ='"+ui->cgq->currentText()+"'and tj = '"+ui->tj->currentText()+"'");
        if (q.next()) {
            QMessageBox::warning(this,"添加失败","记录重复","OK");
        }
        else {
            QString tj_n = "";
            if (ui->tj->currentText()==">") {
                tj_n="<";
            }
            else if(ui->tj->currentText()=="<"){
                tj_n=">";
            }
            q.exec("select * from  num where cgq = '"+ui->cgq->currentText()+"' and tj='"+tj_n+"'");
            if (q.next()) {
                if (ui->tj->currentText()=="<") {
                    if (ui->zhi->text().toFloat()>q.value(6).toFloat()) {
                        q.exec("select *from num where mode = '"+ui->select_ml->currentText()+"'");
                        if (q.next()) {
                            QMessageBox::information(this,"保存","保存成功","OK");
                            if (ui->select_ml->currentText()!=q.value(0).toString()) {
                                q.exec("insert into num(mode,dz3,dz1,dz2,cgq,tj,zhi)values('"+ui->select_ml->currentText()+"','"+dz3+"','"+dz1+"','"+dz2+"','"+ui->cgq->currentText()+"','"+ui->tj->currentText()+"','"+ui->zhi->text()+"')");
                                ui->select_ml->addItem(ui->select_ml->currentText());
                            }
                        }
                        else {
                            QMessageBox::information(this,"保存","保存成功","OK");
                            q.exec("insert into num(mode,dz3,dz1,dz2,cgq,tj,zhi)values('"+ui->select_ml->currentText()+"','"+dz3+"','"+dz1+"','"+dz2+"','"+ui->cgq->currentText()+"','"+ui->tj->currentText()+"','"+ui->zhi->text()+"')");
                            ui->select_ml->addItem(ui->select_ml->currentText());
                        }
                    }
                    else {
                        QMessageBox::warning(this,"添加失败","阈值错误","OK");
                    }
                }
                else if (ui->tj->currentText()==">") {
                    if (ui->zhi->text().toFloat()<q.value(6).toFloat()) {
                        q.exec("select *from num where mode = '"+ui->select_ml->currentText()+"'");
                        if (q.next()) {
                            if (ui->select_ml->currentText()!=q.value(0).toString()) {
                                QMessageBox::information(this,"保存","保存成功","OK");
                                q.exec("insert into num(mode,dz3,dz1,dz2,cgq,tj,zhi)values('"+ui->select_ml->currentText()+"','"+dz3+"','"+dz1+"','"+dz2+"','"+ui->cgq->currentText()+"','"+ui->tj->currentText()+"','"+ui->zhi->text()+"')");
                                ui->select_ml->addItem(ui->select_ml->currentText());
                            }
                        }
                        else {
                            QMessageBox::information(this,"保存","保存成功","OK");
                            q.exec("insert into num(mode,dz3,dz1,dz2,cgq,tj,zhi)values('"+ui->select_ml->currentText()+"','"+dz3+"','"+dz1+"','"+dz2+"','"+ui->cgq->currentText()+"','"+ui->tj->currentText()+"','"+ui->zhi->text()+"')");
                            ui->select_ml->addItem(ui->select_ml->currentText());
                        }
                    }
                    else {
                        QMessageBox::warning(this,"添加失败","阈值错误","OK");
                    }
                }
            }
            else {
                q.exec("select *from num where mode = '"+ui->select_ml->currentText()+"'");
                if (q.next()) {
                    if (ui->select_ml->currentText()!=q.value(0).toString()) {
                        QMessageBox::information(this,"保存","保存成功","OK");
                        q.exec("insert into num(mode,dz3,dz1,dz2,cgq,tj,zhi)values('"+ui->select_ml->currentText()+"','"+dz3+"','"+dz1+"','"+dz2+"','"+ui->cgq->currentText()+"','"+ui->tj->currentText()+"','"+ui->zhi->text()+"')");
                        ui->select_ml->addItem(ui->select_ml->currentText());
                    }
                }
                else {
                    QMessageBox::information(this,"保存","保存成功","OK");
                    q.exec("insert into num(mode,dz3,dz1,dz2,cgq,tj,zhi)values('"+ui->select_ml->currentText()+"','"+dz3+"','"+dz1+"','"+dz2+"','"+ui->cgq->currentText()+"','"+ui->tj->currentText()+"','"+ui->zhi->text()+"')");
                    ui->select_ml->addItem(ui->select_ml->currentText());
                }
            }
        }
    }
    else {
        QMessageBox::warning(this,"保存","保存失败","OK");
    }
}

void Dialog::on_delete_1_clicked()
{
    if (ui->select_ml->currentText()!="") {
        q.exec("delete from num where mode = '"+ui->select_ml->currentText()+"'");
        QMessageBox::information(this,"删除","删除成功","OK");
        ui->select_ml->removeItem(ui->select_ml->currentIndex());
        ui->select_ml->clearEditText();
        guan->xx();
    }
    else {
        QMessageBox::warning(this,"删除","删除失败","OK");
    }
}

void Dialog::on_znmode_clicked()
{
    if (ui->znmode->isChecked()) {
        ui->widg->setEnabled(false);
    }
    else {
        ui->widg->setEnabled(true);
    }
}

bool Dialog::eventFilter(QObject *ex, QEvent *ey)
{
    if (ex==ui->maichong_draw&&ey->type()==QEvent::Paint) {
        QPainter p(ui->maichong_draw);
        QPen a;
        a.setWidth(2);
        p.setPen(a);
        p.drawLine(40,0,40,421);
        p.drawLine(0,400,351,400);
        float t = (float)311/60;
        a.setColor(Qt::blue);
        p.setPen(a);
        for (int i = 0; i < mc.size(); ++i) {
            if (mc.at(i)==0) {
                p.drawLine(40+t*i,300,40+t*(i+1),300);
            }
        }
        for (int i = 0; i <  mc.size(); ++i) {
            if (mc.at(i)==1) {
                p.drawLine(40+t*i,400,40+t*(i+1),400);
            }
        }
        bool ff=false;
        for (int i = 0; i < mc.size(); ++i) {
            if (mc.at(i)==0) {
                if (ff==false) {
                    p.drawLine(40+t*i,300,40+t*i,400);
                    ff=true;
                }
            }
            else {
                ff=false;
            }
        }
        bool yy=false;
        for (int i = 0; i < mc.size(); ++i) {
            if (mc.at(i)==1) {
                if (yy==false) {
                    p.drawLine(40+t*i,300,40+t*i,400);
                    yy=true;
                }
            }
            else {
                yy=false;
            }
        }
    }
        else if (ui->cgq_draw&&ey->type()==QEvent::Paint) {
        QPainter pp(ui->cgq_draw);
        QPen aa;
        aa.setWidth(2);
        pp.setPen(aa);
        pp.drawLine(40,20,40,380);
        pp.drawLine(0,350,330,350);
        QList<float> *dl = list.at(yya);
        for (int i = 0; i < 6; ++i) {
            pp.drawText(40+(250/6)+(250/6)*i,370,QString::number(i+1));
        }
        for (int i = 0; i < 11; ++i) {
            if (yya==2||yya==4||yya==3) {
                pp.drawText(0,(330/11)+(330/11)*i,QString::number((11-i)*200));
            }
            else {
                pp.drawText(0,(330/11)+(330/11)*i,QString::number((11-i)*20));
            }
        }
        float bl = (float)300/220;
        float dll = (float)310/2200;
        for (int i = 0; i < 5; ++i) {
            if (yya==2||yya==4||yya==3) {
                pp.drawLine(40+(250/6)+(250/6)*i,350-dl->at(i)*dll,40+(250/6)+(250/6)*(i+1),350-dl->at(i+1)*dll);
            }
            else {
                pp.drawLine(40+(250/6)+(250/6)*i,350-dl->at(i)*bl,40+(250/6)+(250/6)*(i+1),350-dl->at(i+1)*bl);
            }
        }
        for (int i = 0; i < 6; ++i) {
            if (yya==2||yya==4||yya==3) {
                pp.drawEllipse(40+(250/6)+(250/6)*i,350-dl->at(i)*dll-2,4,4);
            }
            else {
                pp.drawEllipse(40+(250/6)+(250/6)*i,350-dl->at(i)*bl-2,4,4);
            }
        }
    }
}

void Dialog::on_see_clicked()
{
    guan->xx();
    guan->hide();
    guan->exec();
}

void Dialog::Click(int i)
{
    switch(i)
    {
    case 0:
        Send(19,RELAY_SERVE,gp->button(i)->isChecked()?SWITCH_ON:SWITCH_OFF,VOL_RELAY,CHANNEL_ALL);
        break;
    case 1:
        Send(4,DC_SERVE,SWITCH_ON,0,CHANNEL_1);
        break;
    case 2:
        Send(20,RELAY_SERVE,gp->button(i)->isChecked()?SWITCH_ON:SWITCH_OFF,VOL_RELAY,CHANNEL_ALL);
        break;
    case 3:
        Send(15,INFRARED_SERVE,0,0,2);
        break;
    case 4:
        Send(5,INFRARED_SERVE,0,0,1);
        break;
    case 5:
        Send(15,INFRARED_SERVE,0,0,3);
        break;
    }
}


void Dialog::on_zj_start_clicked()
{
    if (ui->zj_start->text()=="开始自检") {
        ui->zj_start->setText("停止自检");

        ui->textEdit->append("一."+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"系统开始器件自检");
        ui->textEdit->append("(一)客厅设备");
        ui->textEdit->append("温度传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->textEdit->append("湿度传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->textEdit->append("光照传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->textEdit->append("二氧化碳传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->textEdit->append("气压传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        ui->textEdit->append("PM2.5传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

//        zj_time = startTimer(1000);
//        zj_int=0;

        thread_zj->start();

    }
    else {
        ui->zj_start->setText("开始自检");

        thread_zj->terminate();

//        killTimer(zj_time);
//        zj_int=0;
    }
}

void Dialog::on_chongx_zj_clicked()
{
    zj_int=0;
    qj_int=0;
    ui->textEdit->append("一."+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"系统开始器件自检");
    ui->textEdit->append("(一)客厅设备");
    ui->textEdit->append("温度传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    ui->textEdit->append("湿度传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    ui->textEdit->append("光照传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    ui->textEdit->append("二氧化碳传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    ui->textEdit->append("气压传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    ui->textEdit->append("PM2.5传感器处于活跃状态，板号为1，最近上传数据为"+ui->ppm->text()+"最近一次采集时间为"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    zj_time =startTimer(1000);
}

void Dialog::on_close_clicked()
{
    zj_int=0;
    qj_int=0;
    killTimer(zj_time);
    ui->textEdit->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_ptemp_clicked()
{
    if (ui->ptemp->isChecked()) {
        ui->widget->show();
        ui->drawname->show();
        ui->drawname->setText("温度");
        text = "温度";
        yya=0;
    }
    else {
        ui->widget->hide();
        ui->drawname->hide();
    }
}

void Dialog::on_phum_clicked()
{
    if (ui->phum->isChecked()) {
        ui->widget->show();
        ui->drawname->show();
        ui->drawname->setText("湿度");
        text = "湿度";
        yya=1;
    }
    else {
        ui->widget->hide();
        ui->drawname->hide();
    }
}

void Dialog::on_pill_clicked()
{
    if (ui->pill->isChecked()) {
        ui->widget->show();
        ui->drawname->show();
        ui->drawname->setText("光照");
        text = "光照";
        yya=2;
    }
    else {
        ui->widget->hide();
        ui->drawname->hide();
    }
}

void Dialog::on_pco2_clicked()
{
    if (ui->pco2->isChecked()) {
         ui->widget->show();
         ui->drawname->show();
         ui->drawname->setText("二氧化碳");
         text = "二氧化碳";
         yya=3;
    }
    else {
        ui->widget->hide();
        ui->drawname->hide();
    }
}

void Dialog::on_pap_clicked()
{
    if (ui->pap->isChecked()) {
        ui->widget->show();
        ui->drawname->show();
        ui->drawname->setText("气压");
        text = "气压";
        yya=4;
    }
    else {
        ui->widget->hide();
        ui->drawname->hide();
    }
}

void Dialog::on_ppm_clicked()
{
    if (ui->ppm->isChecked()) {
        ui->widget->show();
        ui->drawname->show();
        ui->drawname->setText("PM2.5");
        text = "PM2.5";
        yya=5;
    }
    else {
        ui->widget->hide();
        ui->drawname->hide();
    }
}

void Dialog::on_cf_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::control(QString device, int on_off)
{
    if(device=="电视")
    {
        if(on_off==1)
        {
            Send(numms[device],INFRARED_SERVE,0,0,2);
            ui->textEdit->append("现在打开电视");
        }
        else
        {
            Send(numms[device],INFRARED_SERVE,0,0,2);
            ui->textEdit->append("现在关闭电视");
        }
    }
    else if(device=="空调")
    {
        if(on_off==1)
        {
            Send(numms[device],INFRARED_SERVE,0,0,1);
            ui->textEdit->append("现在打开空调");
        }
        else
        {
            Send(numms[device],INFRARED_SERVE,0,0,1);
            ui->textEdit->append("现在关闭空调");
        }
    }
    else if(device=="DVD")
    {
        if(on_off==1)
        {
            Send(numms[device],INFRARED_SERVE,0,0,3);
            ui->textEdit->append("现在打开DVD");
        }
        else
        {
            Send(numms[device],INFRARED_SERVE,0,0,3);
            ui->textEdit->append("现在关闭DVD");
        }
    }
    else if(device=="加湿器")
    {
        if(on_off==1)
        {
            Send(numms[device],INFRARED_SERVE,0,0,4);
            ui->textEdit->append("现在打开加湿器");
        }
        else
        {
            Send(numms[device],INFRARED_SERVE,0,0,4);
            ui->textEdit->append("现在关闭加湿器");
        }
    }
    else if(device=="窗帘")
    {
        if(on_off==1)
        {
            Send(numms[device],RELAY_SERVE,SWITCH_ON,NODE_RELAY,CHANNEL_1);
            ui->textEdit->append("现在打开窗帘");
        }
        else
        {
            Send(numms[device],RELAY_SERVE,SWITCH_ON,NODE_RELAY,CHANNEL_3);
            ui->textEdit->append("现在关闭窗帘");
        }
    }
    else if(device=="结束")
    {
        ui->textEdit->append("自检结束");
        ui->zj_start->setText("开始自检");
        ui->zj_start->setChecked(false);
    }
}

void Dialog::on_fanh_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_fanh_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void Dialog::on_fanh_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void Dialog::on_fanh_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
