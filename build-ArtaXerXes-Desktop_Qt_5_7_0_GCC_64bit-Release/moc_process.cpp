/****************************************************************************
** Meta object code from reading C++ file 'process.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ArtaXerXes/process.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'process.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Process_t {
    QByteArrayData data[21];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Process_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Process_t qt_meta_stringdata_Process = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Process"
QT_MOC_LITERAL(1, 8, 11), // "HazmatStart"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "HazmatTakiStart"
QT_MOC_LITERAL(4, 37, 14), // "HazmatDetected"
QT_MOC_LITERAL(5, 52, 3), // "Mat"
QT_MOC_LITERAL(6, 56, 1), // "a"
QT_MOC_LITERAL(7, 58, 1), // "x"
QT_MOC_LITERAL(8, 60, 1), // "b"
QT_MOC_LITERAL(9, 62, 1), // "c"
QT_MOC_LITERAL(10, 64, 1), // "d"
QT_MOC_LITERAL(11, 66, 18), // "HazmattakiDetected"
QT_MOC_LITERAL(12, 85, 1), // "e"
QT_MOC_LITERAL(13, 87, 7), // "QRStart"
QT_MOC_LITERAL(14, 95, 11), // "QRDetection"
QT_MOC_LITERAL(15, 107, 11), // "motionStart"
QT_MOC_LITERAL(16, 119, 15), // "motionDetection"
QT_MOC_LITERAL(17, 135, 7), // "prosses"
QT_MOC_LITERAL(18, 143, 11), // "prossesTaki"
QT_MOC_LITERAL(19, 155, 7), // "QR_scan"
QT_MOC_LITERAL(20, 163, 6) // "motion"

    },
    "Process\0HazmatStart\0\0HazmatTakiStart\0"
    "HazmatDetected\0Mat\0a\0x\0b\0c\0d\0"
    "HazmattakiDetected\0e\0QRStart\0QRDetection\0"
    "motionStart\0motionDetection\0prosses\0"
    "prossesTaki\0QR_scan\0motion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Process[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    5,   76,    2, 0x06 /* Public */,
      11,    6,   87,    2, 0x06 /* Public */,
      13,    0,  100,    2, 0x06 /* Public */,
      14,    2,  101,    2, 0x06 /* Public */,
      15,    0,  106,    2, 0x06 /* Public */,
      16,    2,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  112,    2, 0x0a /* Public */,
      18,    5,  113,    2, 0x0a /* Public */,
      19,    0,  124,    2, 0x0a /* Public */,
      20,    0,  125,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,    6,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Process::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Process *_t = static_cast<Process *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->HazmatStart(); break;
        case 1: _t->HazmatTakiStart(); break;
        case 2: _t->HazmatDetected((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->HazmattakiDetected((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 4: _t->QRStart(); break;
        case 5: _t->QRDetection((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->motionStart(); break;
        case 7: _t->motionDetection((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->prosses(); break;
        case 9: _t->prossesTaki((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 10: _t->QR_scan(); break;
        case 11: _t->motion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Process::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::HazmatStart)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Process::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::HazmatTakiStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Process::*_t)(Mat , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::HazmatDetected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Process::*_t)(Mat , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::HazmattakiDetected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Process::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::QRStart)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Process::*_t)(Mat , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::QRDetection)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Process::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::motionStart)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Process::*_t)(Mat , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::motionDetection)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject Process::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Process.data,
      qt_meta_data_Process,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Process::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Process::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Process.stringdata0))
        return static_cast<void*>(const_cast< Process*>(this));
    return QObject::qt_metacast(_clname);
}

int Process::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Process::HazmatStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Process::HazmatTakiStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Process::HazmatDetected(Mat _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Process::HazmattakiDetected(Mat _t1, int _t2, int _t3, int _t4, int _t5, int _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Process::QRStart()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Process::QRDetection(Mat _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Process::motionStart()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Process::motionDetection(Mat _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
