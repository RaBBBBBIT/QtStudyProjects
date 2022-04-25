/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Sun Mar 6 10:24:38 2022
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *wl;
    QPushButton *door;
    QPushButton *kt_push;
    QPushButton *pushButton_4;
    QPushButton *cf;
    QLabel *label_7;
    QPushButton *cf_2;
    QPushButton *cf_3;
    QPushButton *cf_4;
    QPushButton *cf_5;
    QPushButton *cf_6;
    QPushButton *cf_7;
    QPushButton *cf_8;
    QPushButton *cf_9;
    QWidget *page_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *gas;
    QPushButton *fan;
    QLabel *label_8;
    QLineEdit *gas_int;
    QLabel *label_19;
    QPushButton *fanh;
    QWidget *page_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label_3;
    QPushButton *zj_start;
    QPushButton *chongx_zj;
    QPushButton *close;
    QWidget *page_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_9;
    QSlider *temp;
    QLabel *label_10;
    QLabel *label_11;
    QSlider *hum;
    QLabel *label_12;
    QSlider *ill;
    QLabel *label_13;
    QSlider *co2;
    QLabel *label_14;
    QSlider *ap;
    QLabel *label_15;
    QSlider *pmm;
    QWidget *widget;
    QLabel *cgq_draw;
    QLabel *drawname;
    QPushButton *ptemp;
    QPushButton *phum;
    QPushButton *pill;
    QPushButton *pco2;
    QPushButton *pap;
    QPushButton *ppm;
    QLabel *label_17;
    QSpinBox *spinBox;
    QLabel *label_18;
    QPushButton *fanh_2;
    QWidget *tab_3;
    QLabel *label_16;
    QWidget *widget_2;
    QLabel *maichong_draw;
    QWidget *widg;
    QRadioButton *dvd;
    QRadioButton *tv;
    QRadioButton *kt;
    QSpinBox *spinBox_2;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *fanh_3;
    QWidget *tab_2;
    QLabel *label_20;
    QLabel *label_21;
    QComboBox *cgq;
    QComboBox *tj;
    QLineEdit *zhi;
    QCheckBox *znmode;
    QPushButton *save;
    QPushButton *delete_1;
    QTextEdit *textEdit_2;
    QPushButton *see;
    QFontComboBox *select_ml;
    QComboBox *qj;
    QPushButton *fanh_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 480);
        stackedWidget = new QStackedWidget(Dialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 480));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 480));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/7202.jpg);"));
        wl = new QPushButton(page);
        wl->setObjectName(QString::fromUtf8("wl"));
        wl->setGeometry(QRect(70, 420, 61, 61));
        wl->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-image: url(:/draw/3204.png);\n"
"}\n"
"QPushButton::checked\n"
"{\n"
"	border-image: url(:/draw/3205.png);\n"
"}"));
        wl->setCheckable(true);
        wl->setChecked(false);
        door = new QPushButton(page);
        door->setObjectName(QString::fromUtf8("door"));
        door->setGeometry(QRect(0, 400, 61, 71));
        door->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/1215.png);"));
        kt_push = new QPushButton(page);
        kt_push->setObjectName(QString::fromUtf8("kt_push"));
        kt_push->setGeometry(QRect(310, 270, 121, 101));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(687, 410, 71, 51));
        cf = new QPushButton(page);
        cf->setObjectName(QString::fromUtf8("cf"));
        cf->setGeometry(QRect(50, 70, 131, 81));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 20, 131, 17));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        cf_2 = new QPushButton(page);
        cf_2->setObjectName(QString::fromUtf8("cf_2"));
        cf_2->setGeometry(QRect(230, 40, 131, 81));
        cf_3 = new QPushButton(page);
        cf_3->setObjectName(QString::fromUtf8("cf_3"));
        cf_3->setGeometry(QRect(390, 40, 131, 81));
        cf_4 = new QPushButton(page);
        cf_4->setObjectName(QString::fromUtf8("cf_4"));
        cf_4->setGeometry(QRect(530, 40, 211, 121));
        cf_5 = new QPushButton(page);
        cf_5->setObjectName(QString::fromUtf8("cf_5"));
        cf_5->setGeometry(QRect(40, 170, 241, 91));
        cf_6 = new QPushButton(page);
        cf_6->setObjectName(QString::fromUtf8("cf_6"));
        cf_6->setGeometry(QRect(420, 170, 241, 91));
        cf_7 = new QPushButton(page);
        cf_7->setObjectName(QString::fromUtf8("cf_7"));
        cf_7->setGeometry(QRect(30, 300, 181, 71));
        cf_8 = new QPushButton(page);
        cf_8->setObjectName(QString::fromUtf8("cf_8"));
        cf_8->setGeometry(QRect(560, 290, 181, 71));
        cf_9 = new QPushButton(page);
        cf_9->setObjectName(QString::fromUtf8("cf_9"));
        cf_9->setGeometry(QRect(260, 390, 251, 71));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 800, 480));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/7202.jpg);"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 61, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 90, 41, 17));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gas = new QLabel(page_3);
        gas->setObjectName(QString::fromUtf8("gas"));
        gas->setGeometry(QRect(70, 90, 67, 17));
        gas->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        fan = new QPushButton(page_3);
        fan->setObjectName(QString::fromUtf8("fan"));
        fan->setGeometry(QRect(470, 120, 61, 61));
        fan->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	\n"
"	border-image: url(:/draw/0119.png);\n"
"}\n"
"QPushButton::checked\n"
"{\n"
"	\n"
"	border-image: url(:/draw/0120.png);\n"
"}"));
        fan->setCheckable(true);
        fan->setChecked(false);
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 170, 67, 17));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        gas_int = new QLineEdit(page_3);
        gas_int->setObjectName(QString::fromUtf8("gas_int"));
        gas_int->setGeometry(QRect(100, 160, 113, 27));
        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(220, 170, 91, 20));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 0);"));
        fanh = new QPushButton(page_3);
        fanh->setObjectName(QString::fromUtf8("fanh"));
        fanh->setGeometry(QRect(580, 260, 98, 27));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 800, 480));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/7202.jpg);"));
        textEdit = new QTextEdit(page_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 60, 591, 331));
        textEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 181, 17));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        zj_start = new QPushButton(page_2);
        zj_start->setObjectName(QString::fromUtf8("zj_start"));
        zj_start->setGeometry(QRect(100, 420, 98, 27));
        zj_start->setCheckable(true);
        chongx_zj = new QPushButton(page_2);
        chongx_zj->setObjectName(QString::fromUtf8("chongx_zj"));
        chongx_zj->setGeometry(QRect(320, 420, 98, 27));
        close = new QPushButton(page_2);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(560, 420, 98, 27));
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        tabWidget = new QTabWidget(page_4);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 781, 481));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 0, 421, 441));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/7202.jpg);"));
        temp = new QSlider(tab);
        temp->setObjectName(QString::fromUtf8("temp"));
        temp->setGeometry(QRect(20, 40, 29, 251));
        temp->setStyleSheet(QString::fromUtf8("QSlider:handle\n"
"{\n"
"	background-color: rgb(255, 85, 0,0);\n"
"}"));
        temp->setOrientation(Qt::Vertical);
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 300, 41, 17));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(80, 300, 41, 17));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        hum = new QSlider(tab);
        hum->setObjectName(QString::fromUtf8("hum"));
        hum->setGeometry(QRect(80, 40, 29, 251));
        hum->setStyleSheet(QString::fromUtf8("QSlider:handle\n"
"{\n"
"	background-color: rgb(255, 85, 0,0);\n"
"}"));
        hum->setOrientation(Qt::Vertical);
        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 300, 51, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ill = new QSlider(tab);
        ill->setObjectName(QString::fromUtf8("ill"));
        ill->setGeometry(QRect(150, 40, 29, 251));
        ill->setStyleSheet(QString::fromUtf8("QSlider:handle\n"
"{\n"
"	background-color: rgb(255, 85, 0,0);\n"
"}"));
        ill->setOrientation(Qt::Vertical);
        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(200, 300, 61, 17));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        co2 = new QSlider(tab);
        co2->setObjectName(QString::fromUtf8("co2"));
        co2->setGeometry(QRect(210, 40, 29, 251));
        co2->setStyleSheet(QString::fromUtf8("QSlider:handle\n"
"{\n"
"	background-color: rgb(255, 85, 0,0);\n"
"}"));
        co2->setOrientation(Qt::Vertical);
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 300, 41, 17));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ap = new QSlider(tab);
        ap->setObjectName(QString::fromUtf8("ap"));
        ap->setGeometry(QRect(290, 40, 29, 251));
        ap->setStyleSheet(QString::fromUtf8("QSlider:handle\n"
"{\n"
"	background-color: rgb(255, 85, 0,0);\n"
"}"));
        ap->setOrientation(Qt::Vertical);
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(360, 300, 41, 17));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pmm = new QSlider(tab);
        pmm->setObjectName(QString::fromUtf8("pmm"));
        pmm->setGeometry(QRect(360, 40, 29, 251));
        pmm->setStyleSheet(QString::fromUtf8("QSlider:handle\n"
"{\n"
"	background-color: rgb(255, 85, 0,0);\n"
"}"));
        pmm->setOrientation(Qt::Vertical);
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(430, 30, 351, 411));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        cgq_draw = new QLabel(widget);
        cgq_draw->setObjectName(QString::fromUtf8("cgq_draw"));
        cgq_draw->setGeometry(QRect(10, 30, 330, 371));
        cgq_draw->setStyleSheet(QString::fromUtf8(""));
        drawname = new QLabel(widget);
        drawname->setObjectName(QString::fromUtf8("drawname"));
        drawname->setGeometry(QRect(120, 30, 67, 17));
        ptemp = new QPushButton(tab);
        ptemp->setObjectName(QString::fromUtf8("ptemp"));
        ptemp->setGeometry(QRect(0, 280, 61, 21));
        ptemp->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/2201.jpg);"));
        ptemp->setCheckable(true);
        ptemp->setFlat(true);
        phum = new QPushButton(tab);
        phum->setObjectName(QString::fromUtf8("phum"));
        phum->setGeometry(QRect(70, 280, 61, 21));
        phum->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/2201.jpg);"));
        phum->setCheckable(true);
        pill = new QPushButton(tab);
        pill->setObjectName(QString::fromUtf8("pill"));
        pill->setGeometry(QRect(140, 280, 61, 21));
        pill->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/2201.jpg);"));
        pill->setCheckable(true);
        pco2 = new QPushButton(tab);
        pco2->setObjectName(QString::fromUtf8("pco2"));
        pco2->setGeometry(QRect(210, 280, 61, 21));
        pco2->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/2201.jpg);"));
        pco2->setCheckable(true);
        pap = new QPushButton(tab);
        pap->setObjectName(QString::fromUtf8("pap"));
        pap->setGeometry(QRect(280, 280, 61, 21));
        pap->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/2201.jpg);"));
        pap->setCheckable(true);
        ppm = new QPushButton(tab);
        ppm->setObjectName(QString::fromUtf8("ppm"));
        ppm->setGeometry(QRect(350, 280, 61, 21));
        ppm->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/2201.jpg);"));
        ppm->setCheckable(true);
        label_17 = new QLabel(tab);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(436, 10, 121, 20));
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(570, 0, 59, 27));
        spinBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        spinBox->setValue(60);
        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(640, 10, 41, 17));
        fanh_2 = new QPushButton(tab);
        fanh_2->setObjectName(QString::fromUtf8("fanh_2"));
        fanh_2->setGeometry(QRect(310, 400, 98, 27));
        tabWidget->addTab(tab, QString());
        label_9->raise();
        label_11->raise();
        label_13->raise();
        label_15->raise();
        temp->raise();
        hum->raise();
        ill->raise();
        label_10->raise();
        co2->raise();
        label_12->raise();
        ap->raise();
        label_14->raise();
        pmm->raise();
        widget->raise();
        ptemp->raise();
        phum->raise();
        pill->raise();
        pco2->raise();
        pap->raise();
        ppm->raise();
        label_17->raise();
        spinBox->raise();
        label_18->raise();
        fanh_2->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 10, 411, 441));
        label_16->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/7202.jpg);"));
        widget_2 = new QWidget(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(410, 30, 371, 421));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        maichong_draw = new QLabel(widget_2);
        maichong_draw->setObjectName(QString::fromUtf8("maichong_draw"));
        maichong_draw->setGeometry(QRect(10, 0, 351, 411));
        widg = new QWidget(tab_3);
        widg->setObjectName(QString::fromUtf8("widg"));
        widg->setGeometry(QRect(70, 120, 221, 181));
        dvd = new QRadioButton(widg);
        dvd->setObjectName(QString::fromUtf8("dvd"));
        dvd->setGeometry(QRect(60, 100, 61, 22));
        dvd->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        dvd->setAutoExclusive(false);
        tv = new QRadioButton(widg);
        tv->setObjectName(QString::fromUtf8("tv"));
        tv->setGeometry(QRect(60, 40, 61, 22));
        tv->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        tv->setCheckable(true);
        tv->setAutoExclusive(false);
        kt = new QRadioButton(widg);
        kt->setObjectName(QString::fromUtf8("kt"));
        kt->setGeometry(QRect(60, 70, 61, 22));
        kt->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        kt->setAutoExclusive(false);
        spinBox_2 = new QSpinBox(tab_3);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(594, 0, 59, 27));
        spinBox_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        spinBox_2->setValue(60);
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(664, 10, 41, 17));
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(460, 10, 121, 20));
        fanh_3 = new QPushButton(tab_3);
        fanh_3->setObjectName(QString::fromUtf8("fanh_3"));
        fanh_3->setGeometry(QRect(300, 400, 98, 27));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 0, 791, 441));
        label_20->setStyleSheet(QString::fromUtf8("border-image: url(:/draw/7202.jpg);"));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 10, 101, 17));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        cgq = new QComboBox(tab_2);
        cgq->setObjectName(QString::fromUtf8("cgq"));
        cgq->setGeometry(QRect(220, 60, 121, 27));
        tj = new QComboBox(tab_2);
        tj->setObjectName(QString::fromUtf8("tj"));
        tj->setGeometry(QRect(350, 60, 101, 27));
        zhi = new QLineEdit(tab_2);
        zhi->setObjectName(QString::fromUtf8("zhi"));
        zhi->setGeometry(QRect(460, 60, 113, 27));
        znmode = new QCheckBox(tab_2);
        znmode->setObjectName(QString::fromUtf8("znmode"));
        znmode->setGeometry(QRect(510, 110, 98, 22));
        znmode->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 0, 0);\n"
"color: rgb(255, 255, 127);"));
        save = new QPushButton(tab_2);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(160, 100, 98, 27));
        delete_1 = new QPushButton(tab_2);
        delete_1->setObjectName(QString::fromUtf8("delete_1"));
        delete_1->setGeometry(QRect(270, 100, 98, 27));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(70, 150, 651, 251));
        see = new QPushButton(tab_2);
        see->setObjectName(QString::fromUtf8("see"));
        see->setGeometry(QRect(380, 100, 98, 27));
        select_ml = new QFontComboBox(tab_2);
        select_ml->setObjectName(QString::fromUtf8("select_ml"));
        select_ml->setGeometry(QRect(60, 60, 151, 27));
        qj = new QComboBox(tab_2);
        qj->setObjectName(QString::fromUtf8("qj"));
        qj->setGeometry(QRect(590, 60, 111, 27));
        fanh_4 = new QPushButton(tab_2);
        fanh_4->setObjectName(QString::fromUtf8("fanh_4"));
        fanh_4->setGeometry(QRect(500, 10, 98, 27));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(page_4);

        retranslateUi(Dialog);

        stackedWidget->setCurrentIndex(3);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        wl->setText(QString());
        door->setText(QString());
        kt_push->setText(QApplication::translate("Dialog", "\345\256\242\345\216\205", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Dialog", "\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        cf->setText(QApplication::translate("Dialog", "\345\216\250\346\210\277", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "\346\210\221\345\217\270\346\240\267\346\235\277\346\210\277118\343\216\241", 0, QApplication::UnicodeUTF8));
        cf_2->setText(QApplication::translate("Dialog", "\345\215\253\347\224\237\351\227\264\343\200\220\345\256\242\343\200\221", 0, QApplication::UnicodeUTF8));
        cf_3->setText(QApplication::translate("Dialog", "\345\215\253\347\224\237\351\227\2642\343\200\220\344\270\273\343\200\221", 0, QApplication::UnicodeUTF8));
        cf_4->setText(QApplication::translate("Dialog", "\345\215\247\345\256\244\343\200\220\345\214\227\343\200\221", 0, QApplication::UnicodeUTF8));
        cf_5->setText(QApplication::translate("Dialog", "\351\244\220\345\216\205", 0, QApplication::UnicodeUTF8));
        cf_6->setText(QApplication::translate("Dialog", "\344\271\246\346\210\277", 0, QApplication::UnicodeUTF8));
        cf_7->setText(QApplication::translate("Dialog", "\345\215\247\345\256\244\343\200\220\345\215\227\350\245\277\343\200\221", 0, QApplication::UnicodeUTF8));
        cf_8->setText(QApplication::translate("Dialog", "\345\215\247\345\256\244\343\200\220\345\215\227\344\270\234\343\200\221", 0, QApplication::UnicodeUTF8));
        cf_9->setText(QApplication::translate("Dialog", "\351\230\263\345\217\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("Dialog", "\345\216\250\346\210\277", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "\347\207\203\346\260\224\357\274\232", 0, QApplication::UnicodeUTF8));
        gas->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        fan->setText(QString());
        label_8->setText(QApplication::translate("Dialog", "\347\207\203\346\260\224>", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Dialog", "\351\243\216\346\211\207\345\222\214\346\212\245\350\255\246\347\201\257", 0, QApplication::UnicodeUTF8));
        fanh->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Dialog", "\346\210\221\345\217\270\346\240\267\346\235\277\346\210\277 \347\263\273\347\273\237\350\207\252\346\243\200\344\270\255", 0, QApplication::UnicodeUTF8));
        zj_start->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        chongx_zj->setText(QApplication::translate("Dialog", "\351\207\215\346\226\260\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("Dialog", "\347\273\223\346\235\237", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        label_10->setText(QApplication::translate("Dialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Dialog", "\345\205\211\347\205\247\345\272\246", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Dialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Dialog", "\346\260\224\345\216\213", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Dialog", "PM2.5", 0, QApplication::UnicodeUTF8));
        cgq_draw->setText(QString());
        drawname->setText(QString());
        ptemp->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        phum->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        pill->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        pco2->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        pap->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        ppm->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Dialog", "\345\216\206\345\217\262\346\225\260\346\215\256\346\227\266\345\270\270\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Dialog", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        fanh_2->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "\346\210\277\351\227\264\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_16->setText(QString());
        maichong_draw->setText(QString());
        dvd->setText(QApplication::translate("Dialog", "DVD", 0, QApplication::UnicodeUTF8));
        tv->setText(QApplication::translate("Dialog", "\347\224\265\350\247\206", 0, QApplication::UnicodeUTF8));
        kt->setText(QApplication::translate("Dialog", "\347\251\272\350\260\203", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Dialog", "\345\210\206\351\222\237", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Dialog", "\345\216\206\345\217\262\346\225\260\346\215\256\346\227\266\345\270\270\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        fanh_3->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dialog", "\346\231\272\350\203\275\350\256\276\345\244\207\346\211\213\345\267\245\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("Dialog", "\350\256\276\345\244\207\346\216\247\345\210\266\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        cgq->clear();
        cgq->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\350\257\267\351\200\211\346\213\251\344\274\240\346\204\237\345\231\250", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\347\203\237\351\233\276", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\345\205\211\347\205\247", 0, QApplication::UnicodeUTF8)
        );
        tj->clear();
        tj->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\350\257\267\351\200\211\346\213\251\346\235\241\344\273\266", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", ">", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "<", 0, QApplication::UnicodeUTF8)
        );
        zhi->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\256\276\347\275\256\351\230\210\345\200\274", 0, QApplication::UnicodeUTF8));
        znmode->setText(QApplication::translate("Dialog", "\346\231\272\350\203\275\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("Dialog", "\344\277\235\345\255\230\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        delete_1->setText(QApplication::translate("Dialog", "\345\210\240\351\231\244\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        see->setText(QApplication::translate("Dialog", "\346\237\245\347\234\213\345\221\275\344\273\244", 0, QApplication::UnicodeUTF8));
        qj->clear();
        qj->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\350\257\267\351\200\211\346\213\251\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\347\251\272\350\260\203", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\351\243\216\346\211\207", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\347\252\227\345\270\230", 0, QApplication::UnicodeUTF8)
        );
        fanh_4->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "\346\231\272\350\203\275\350\256\276\345\244\207\350\207\252\345\212\250\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
