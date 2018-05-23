/****************************************************************************
** Meta object code from reading C++ file 'cam.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ArtaXerXes/cam.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cam.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cam_t {
    QByteArrayData data[7];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cam_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cam_t qt_meta_stringdata_Cam = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Cam"
QT_MOC_LITERAL(1, 4, 10), // "imageReady"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 3), // "Mat"
QT_MOC_LITERAL(4, 20, 1), // "a"
QT_MOC_LITERAL(5, 22, 1), // "i"
QT_MOC_LITERAL(6, 24, 12) // "update_frame"

    },
    "Cam\0imageReady\0\0Mat\0a\0i\0update_frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cam[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       1,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QImage,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Cam::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cam *_t = static_cast<Cam *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageReady((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->imageReady((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->update_frame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cam::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cam::imageReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Cam::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cam::imageReady)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Cam::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cam.data,
      qt_meta_data_Cam,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cam::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cam::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cam.stringdata0))
        return static_cast<void*>(const_cast< Cam*>(this));
    return QObject::qt_metacast(_clname);
}

int Cam::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Cam::imageReady(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cam::imageReady(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
