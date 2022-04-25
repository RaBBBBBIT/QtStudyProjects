#ifndef THREAD_ZJ_H
#define THREAD_ZJ_H

#include <QThread>

class Thread_zj : public QThread
{
    Q_OBJECT
public:
    explicit Thread_zj(QObject *parent = 0);

    void run();
    
signals:
    void control(QString device, int on_off);
    
public slots:
    
};

#endif // THREAD_ZJ_H
