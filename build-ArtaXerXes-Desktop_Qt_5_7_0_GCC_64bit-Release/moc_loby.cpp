/****************************************************************************
** Meta object code from reading C++ file 'loby.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ArtaXerXes/loby.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loby.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Loby_t {
    QByteArrayData data[24];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Loby_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Loby_t qt_meta_stringdata_Loby = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Loby"
QT_MOC_LITERAL(1, 5, 16), // "robotmode_signal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "mode"
QT_MOC_LITERAL(4, 28, 10), // "tabChanged"
QT_MOC_LITERAL(5, 39, 1), // "s"
QT_MOC_LITERAL(6, 41, 16), // "thresholdSetting"
QT_MOC_LITERAL(7, 58, 1), // "T"
QT_MOC_LITERAL(8, 60, 5), // "value"
QT_MOC_LITERAL(9, 66, 7), // "getMat1"
QT_MOC_LITERAL(10, 74, 3), // "Mat"
QT_MOC_LITERAL(11, 78, 1), // "a"
QT_MOC_LITERAL(12, 80, 7), // "getMat2"
QT_MOC_LITERAL(13, 88, 7), // "getMat3"
QT_MOC_LITERAL(14, 96, 7), // "getMat4"
QT_MOC_LITERAL(15, 104, 16), // "MotionProcessing"
QT_MOC_LITERAL(16, 121, 12), // "QrProcessing"
QT_MOC_LITERAL(17, 134, 11), // "data_sender"
QT_MOC_LITERAL(18, 146, 15), // "getGamepadState"
QT_MOC_LITERAL(19, 162, 10), // "btn_number"
QT_MOC_LITERAL(20, 173, 6), // "status"
QT_MOC_LITERAL(21, 180, 15), // "getKeboardState"
QT_MOC_LITERAL(22, 196, 1), // "k"
QT_MOC_LITERAL(23, 198, 22) // "main_feedback_is_ready"

    },
    "Loby\0robotmode_signal\0\0mode\0tabChanged\0"
    "s\0thresholdSetting\0T\0value\0getMat1\0"
    "Mat\0a\0getMat2\0getMat3\0getMat4\0"
    "MotionProcessing\0QrProcessing\0data_sender\0"
    "getGamepadState\0btn_number\0status\0"
    "getKeboardState\0k\0main_feedback_is_ready"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Loby[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    2,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   90,    2, 0x08 /* Private */,
      12,    1,   93,    2, 0x08 /* Private */,
      13,    1,   96,    2, 0x08 /* Private */,
      14,    1,   99,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    2,  105,    2, 0x08 /* Private */,
      21,    1,  110,    2, 0x08 /* Private */,
      23,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   19,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,

       0        // eod
};

void Loby::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Loby *_t = static_cast<Loby *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->robotmode_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->tabChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->thresholdSetting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->getMat1((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 4: _t->getMat2((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 5: _t->getMat3((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 6: _t->getMat4((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 7: _t->MotionProcessing(); break;
        case 8: _t->QrProcessing(); break;
        case 9: _t->data_sender(); break;
        case 10: _t->getGamepadState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->getKeboardState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->main_feedback_is_ready(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Loby::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Loby::robotmode_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Loby::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Loby::tabChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Loby::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Loby::thresholdSetting)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Loby::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Loby.data,
      qt_meta_data_Loby,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Loby::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Loby::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Loby.stringdata0))
        return static_cast<void*>(const_cast< Loby*>(this));
    return QObject::qt_metacast(_clname);
}

int Loby::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Loby::robotmode_signal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Loby::tabChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Loby::thresholdSetting(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
