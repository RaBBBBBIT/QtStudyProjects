#include "serialthread.h"
#include <QDebug>
PortSettings a = {BAUD115200,DATA_8,PAR_EVEN,STOP_1,FLOW_OFF};
SerialThread::SerialThread()
{
    port = NULL;
}

int SerialThread::OnPort()
{
    if (port==NULL) {
        port = new QextSerialPort("/dev/ttyUSB0",a,QextSerialPort::EventDriven);
    }
    if (port->isOpen()) {
          return 0;
    }
    if (port->open(QIODevice::ReadWrite)) {
        receive = new SerialPortReceive();
        connect(port,SIGNAL(readyRead()),this,SLOT(OnRead()));
        connect(receive,SIGNAL(byteFinish(QByteArray)),handle,SLOT(receive(QByteArray)));
        return 0;
    }
    else {
        qDebug()<<"打开失败";
        return -1;
    }
}

int SerialThread::Send(QByteArray a)
{
    int b =-1;
    if (port->isOpen()) {
        port->flush();
        b = port->write(a);
    }
    return b;
}

void SerialThread::OnRead()
{
    receive->dataHandle(port->readAll());
}
