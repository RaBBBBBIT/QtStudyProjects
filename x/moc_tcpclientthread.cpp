/****************************************************************************
** Meta object code from reading C++ file 'tcpclientthread.h'
**
** Created: Sun Mar 6 10:24:46 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpclientthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclientthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpClientThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      54,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     102,   16,   16,   16, 0x0a,
     120,   16,   16,   16, 0x08,
     135,   16,   16,   16, 0x08,
     179,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpClientThread[] = {
    "TcpClientThread\0\0boardId,type,command,cmdCode,channel\0"
    "evt_socket_receive(uint,QString,uint,uint,uint)\0"
    "slot_threadQuit()\0slot_receive()\0"
    "slot_breakoff(QAbstractSocket::SocketError)\0"
    "slot_heatBeat()\0"
};

void TcpClientThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpClientThread *_t = static_cast<TcpClientThread *>(_o);
        switch (_id) {
        case 0: _t->evt_socket_receive((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5]))); break;
        case 1: _t->slot_threadQuit(); break;
        case 2: _t->slot_receive(); break;
        case 3: _t->slot_breakoff((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->slot_heatBeat(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TcpClientThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpClientThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpClientThread,
      qt_meta_data_TcpClientThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpClientThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpClientThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpClientThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClientThread))
        return static_cast<void*>(const_cast< TcpClientThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpClientThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TcpClientThread::evt_socket_receive(unsigned int _t1, QString _t2, unsigned int _t3, unsigned int _t4, unsigned int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
