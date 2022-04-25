#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "serialdatahandle.h"
#include "serialthread.h"
#include "tcpclientthread.h"
#include "QtGui"
#include "sql.h"
#include "guan.h"
#include "thread_zj.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Guan *guan;
    SerialDataHandle *handle;
    SerialThread *ser;
    TcpClientThread *tcp;
    void timerEvent(QTimerEvent *e);
    void sx();
    void Send(unsigned int boardId,QString type,unsigned int cmd,unsigned int cmdCode,unsigned int channel);
    QMap<QString,float> nums;
    QMap<QString,float> numms;
    QMap<QString,float> nummms;
    QSqlQuery q;
    int time,mode;
    bool state_ct,state_fan,state_kt;
    bool state_tv,state_dvd,state_wl;
    bool eventFilter(QObject *ex, QEvent *ey);
    int maichong_int;
    QButtonGroup *gp;
    QList<int> mc;
    int zj_int,zj_time;
    QList<QString> list_cgq1;
    int qj_int;
    QList<float> temp_list;
    QList<float> hum_list;
    QList<float> ill_list;
    QList<float> co_list;
    QList<float> ap_list;
    QList<float> pm_list;
    QList<QList<float> *> list;
    QList<QString> list_cgq;
    QString text;
    int yya;
    int time_i,time_i_time;
    int zj_time_time;
    int time_i2,time_i_time2;

    Thread_zj *thread_zj;

private slots:
    void Click(int i);
    void OnReceive(unsigned int boardId,QString type,unsigned int cmd,unsigned int cmdCode,unsigned int channel);
    void SetData(const QString &,const QString &,const QString & ,const QString & );

    void on_kt_push_clicked();

    void on_save_clicked();

    void on_delete_1_clicked();

    void on_znmode_clicked();

    void on_see_clicked();


    void on_zj_start_clicked();

    void on_chongx_zj_clicked();

    void on_close_clicked();

    void on_pushButton_4_clicked();

    void on_ptemp_clicked();

    void on_phum_clicked();

    void on_pill_clicked();

    void on_pco2_clicked();

    void on_pap_clicked();

    void on_ppm_clicked();

    void on_cf_clicked();
    void control(QString device, int on_off);

    void on_fanh_clicked();

    void on_fanh_4_clicked();

    void on_fanh_3_clicked();

    void on_fanh_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
