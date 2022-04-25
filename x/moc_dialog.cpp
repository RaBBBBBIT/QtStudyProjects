/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created: Sun Mar 6 10:24:43 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x08,
      54,   21,    7,    7, 0x08,
      97,   93,    7,    7, 0x08,
     138,    7,    7,    7, 0x08,
     159,    7,    7,    7, 0x08,
     177,    7,    7,    7, 0x08,
     199,    7,    7,    7, 0x08,
     219,    7,    7,    7, 0x08,
     236,    7,    7,    7, 0x08,
     258,    7,    7,    7, 0x08,
     281,    7,    7,    7, 0x08,
     300,    7,    7,    7, 0x08,
     326,    7,    7,    7, 0x08,
     345,    7,    7,    7, 0x08,
     363,    7,    7,    7, 0x08,
     381,    7,    7,    7, 0x08,
     399,    7,    7,    7, 0x08,
     416,    7,    7,    7, 0x08,
     433,    7,    7,    7, 0x08,
     463,  449,    7,    7, 0x08,
     484,    7,    7,    7, 0x08,
     502,    7,    7,    7, 0x08,
     522,    7,    7,    7, 0x08,
     542,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Dialog[] = {
    "Dialog\0\0i\0Click(int)\0"
    "boardId,type,cmd,cmdCode,channel\0"
    "OnReceive(uint,QString,uint,uint,uint)\0"
    ",,,\0SetData(QString,QString,QString,QString)\0"
    "on_kt_push_clicked()\0on_save_clicked()\0"
    "on_delete_1_clicked()\0on_znmode_clicked()\0"
    "on_see_clicked()\0on_zj_start_clicked()\0"
    "on_chongx_zj_clicked()\0on_close_clicked()\0"
    "on_pushButton_4_clicked()\0on_ptemp_clicked()\0"
    "on_phum_clicked()\0on_pill_clicked()\0"
    "on_pco2_clicked()\0on_pap_clicked()\0"
    "on_ppm_clicked()\0on_cf_clicked()\0"
    "device,on_off\0control(QString,int)\0"
    "on_fanh_clicked()\0on_fanh_4_clicked()\0"
    "on_fanh_3_clicked()\0on_fanh_2_clicked()\0"
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Dialog *_t = static_cast<Dialog *>(_o);
        switch (_id) {
        case 0: _t->Click((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->OnReceive((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5]))); break;
        case 2: _t->SetData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 3: _t->on_kt_push_clicked(); break;
        case 4: _t->on_save_clicked(); break;
        case 5: _t->on_delete_1_clicked(); break;
        case 6: _t->on_znmode_clicked(); break;
        case 7: _t->on_see_clicked(); break;
        case 8: _t->on_zj_start_clicked(); break;
        case 9: _t->on_chongx_zj_clicked(); break;
        case 10: _t->on_close_clicked(); break;
        case 11: _t->on_pushButton_4_clicked(); break;
        case 12: _t->on_ptemp_clicked(); break;
        case 13: _t->on_phum_clicked(); break;
        case 14: _t->on_pill_clicked(); break;
        case 15: _t->on_pco2_clicked(); break;
        case 16: _t->on_pap_clicked(); break;
        case 17: _t->on_ppm_clicked(); break;
        case 18: _t->on_cf_clicked(); break;
        case 19: _t->control((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->on_fanh_clicked(); break;
        case 21: _t->on_fanh_4_clicked(); break;
        case 22: _t->on_fanh_3_clicked(); break;
        case 23: _t->on_fanh_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog,
      qt_meta_data_Dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
