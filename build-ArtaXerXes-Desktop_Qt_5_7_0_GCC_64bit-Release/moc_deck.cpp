/****************************************************************************
** Meta object code from reading C++ file 'deck.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ArtaXerXes/deck.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Deck_t {
    QByteArrayData data[12];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Deck_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Deck_t qt_meta_stringdata_Deck = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Deck"
QT_MOC_LITERAL(1, 5, 16), // "thermalImIsReady"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "Mat"
QT_MOC_LITERAL(4, 27, 1), // "m"
QT_MOC_LITERAL(5, 29, 15), // "mainDataIsReady"
QT_MOC_LITERAL(6, 45, 15), // "MapImageIsReady"
QT_MOC_LITERAL(7, 61, 20), // "mainDataReadyForSend"
QT_MOC_LITERAL(8, 82, 16), // "thermalreadyRead"
QT_MOC_LITERAL(9, 99, 12), // "mapreadyRead"
QT_MOC_LITERAL(10, 112, 13), // "mainreadyRead"
QT_MOC_LITERAL(11, 126, 12) // "MainDatasend"

    },
    "Deck\0thermalImIsReady\0\0Mat\0m\0"
    "mainDataIsReady\0MapImageIsReady\0"
    "mainDataReadyForSend\0thermalreadyRead\0"
    "mapreadyRead\0mainreadyRead\0MainDatasend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Deck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,
       7,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Deck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Deck *_t = static_cast<Deck *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thermalImIsReady((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 1: _t->mainDataIsReady(); break;
        case 2: _t->MapImageIsReady((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 3: _t->mainDataReadyForSend(); break;
        case 4: _t->thermalreadyRead(); break;
        case 5: _t->mapreadyRead(); break;
        case 6: _t->mainreadyRead(); break;
        case 7: _t->MainDatasend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Deck::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Deck::thermalImIsReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Deck::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Deck::mainDataIsReady)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Deck::*_t)(Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Deck::MapImageIsReady)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Deck::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Deck::mainDataReadyForSend)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Deck::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Deck.data,
      qt_meta_data_Deck,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Deck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Deck::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Deck.stringdata0))
        return static_cast<void*>(const_cast< Deck*>(this));
    return QObject::qt_metacast(_clname);
}

int Deck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Deck::thermalImIsReady(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Deck::mainDataIsReady()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Deck::MapImageIsReady(Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Deck::mainDataReadyForSend()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
