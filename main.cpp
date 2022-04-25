#include <QtGui/QApplication>
#include "dialog.h"
#include "QtGui"
#include "sql.h"
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    Sql sql;
    sql.sqlConnect("db.db");
    QSqlQuery q;
    q.exec("create table login(name varchar,pass varchar)");
    q.exec("create table num(mode varchar,dz3 varchar,dz1 varchar,dz2 varchar,cgq varchar,tj varchar,zhi varchar)");
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    
    return a.exec();
}
