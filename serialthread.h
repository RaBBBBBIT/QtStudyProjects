#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include "serialdatahandle.h"
#include "serialportreceive.h"
#include "QtGui"
#include "qextserialport.h"
class SerialThread : public QObject
{
    Q_OBJECT
public:
    explicit SerialThread();
    SerialDataHandle *handle;
    SerialPortReceive *receive;
    QextSerialPort *port;
    int OnPort();
    int Send(QByteArray a);
public slots:
    void OnRead();
signals:
    
public slots:
    
};

#endif // SERIALTHREAD_H
