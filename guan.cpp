#include "guan.h"
#include "ui_guan.h"

Guan::Guan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Guan)
{
    ui->setupUi(this);
    setWindowTitle("命令管理");
    m = new QSqlQueryModel();
    m->setQuery("select mode,dz3,dz1,dz2 from num");
    m->setHeaderData(0,Qt::Horizontal,"模式");
    m->setHeaderData(1,Qt::Horizontal,"设置时间");
    m->setHeaderData(2,Qt::Horizontal,"执行条件");
    m->setHeaderData(3,Qt::Horizontal,"执行器件");
    ui->tableView->setModel(m);
    setWindowTitle("命令管理");
}

Guan::~Guan()
{
    delete ui;
}

void Guan::on_fan_clicked()
{
    this->close();
}

void Guan::xx()
{
    m->setQuery("select mode,dz3,dz1,dz2 from num");
    m->setHeaderData(0,Qt::Horizontal,"模式");
    m->setHeaderData(1,Qt::Horizontal,"设置时间");
    m->setHeaderData(2,Qt::Horizontal,"执行条件");
    m->setHeaderData(3,Qt::Horizontal,"执行器件");
    ui->tableView->setModel(m);
}

void Guan::on_shanchu_clicked()
{
    q.exec("delete  from num where mode='"+m->data(m->index(ui->tableView->currentIndex().row(),0)).toString()+"'");
    xx();
}

void Guan::showw()
{
    ui->shanchu->show();
}

void Guan::hide()
{
    ui->shanchu->hide();
}
