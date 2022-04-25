#-------------------------------------------------
#
# Project created by QtCreator 2037-01-16T22:42:28
#
#-------------------------------------------------

QT       += core gui sql network script
LIBS +=./*.so

TARGET = 2022-3-4
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    qextserialport.cpp \
    qextserialport_unix.cpp \
    serialthread.cpp \
    guan.cpp \
    thread_zj.cpp

HEADERS  += dialog.h \
    cjson.h \
    jsonreceivehandle.h \
    jsonsendhandle.h \
    qextserialport.h \
    qextserialport_global.h \
    qextserialport_p.h \
    serialdatahandle.h \
    serialportreceive.h \
    sql.h \
    systemConfig.h \
    tcpclientthread.h \
    tcpserver.h \
    VariableDefinition.h \
    serialthread.h \
    guan.h \
    thread_zj.h

FORMS    += dialog.ui \
    guan.ui

OTHER_FILES += \
    2022-3-4.pro.user

RESOURCES += \
    draw.qrc
