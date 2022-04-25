#include "thread_zj.h"

Thread_zj::Thread_zj(QObject *parent) :
    QThread(parent)
{
}

void Thread_zj::run()
{
    // 电视
    emit control("电视",1);
    sleep(2);
    emit control("电视",0);
    sleep(2);
    //空调
    emit control("空调",1);
    sleep(2);
    emit control("空调",0);
    sleep(2);
    // 窗帘
    emit control("DVD",1);
    sleep(2);
    emit control("DVD",0);
    sleep(2);
    emit control("加湿器",1);
    sleep(2);
    emit control("加湿器",0);
    sleep(2);
    emit control("窗帘",1);
    sleep(5);
    emit control("窗帘",0);
    sleep(5);

    emit control("结束",1);
}
