/********************************************************************************
** Form generated from reading UI file 'guan.ui'
**
** Created: Sun Mar 6 10:24:38 2022
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUAN_H
#define UI_GUAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Guan
{
public:
    QTableView *tableView;
    QPushButton *shanchu;
    QPushButton *fan;

    void setupUi(QDialog *Guan)
    {
        if (Guan->objectName().isEmpty())
            Guan->setObjectName(QString::fromUtf8("Guan"));
        Guan->resize(368, 355);
        tableView = new QTableView(Guan);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 30, 291, 251));
        shanchu = new QPushButton(Guan);
        shanchu->setObjectName(QString::fromUtf8("shanchu"));
        shanchu->setGeometry(QRect(40, 300, 98, 27));
        fan = new QPushButton(Guan);
        fan->setObjectName(QString::fromUtf8("fan"));
        fan->setGeometry(QRect(230, 300, 98, 27));
        shanchu->raise();
        tableView->raise();
        fan->raise();

        retranslateUi(Guan);

        QMetaObject::connectSlotsByName(Guan);
    } // setupUi

    void retranslateUi(QDialog *Guan)
    {
        Guan->setWindowTitle(QApplication::translate("Guan", "Dialog", 0, QApplication::UnicodeUTF8));
        shanchu->setText(QApplication::translate("Guan", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        fan->setText(QApplication::translate("Guan", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Guan: public Ui_Guan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUAN_H
