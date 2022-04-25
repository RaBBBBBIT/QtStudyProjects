#ifndef GUAN_H
#define GUAN_H

#include <QDialog>
#include "QtGui"
#include "sql.h"
namespace Ui {
class Guan;
}

class Guan : public QDialog
{
    Q_OBJECT
    
public:
    explicit Guan(QWidget *parent = 0);
    ~Guan();
    QSqlQuery q;
    QSqlQueryModel *m;
    void xx();
    void showw();
    void hide();
private slots:
    void on_fan_clicked();

    void on_shanchu_clicked();

private:
    Ui::Guan *ui;
};

#endif // GUAN_H
