/****************************************************************************
** Meta object code from reading C++ file 'PjSipadptr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testApp/PjSipadptr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PjSipadptr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PjSipadaptr_t {
    QByteArrayData data[14];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PjSipadaptr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PjSipadaptr_t qt_meta_stringdata_PjSipadaptr = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PjSipadaptr"
QT_MOC_LITERAL(1, 12, 12), // "labelChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 6), // "string"
QT_MOC_LITERAL(4, 33, 14), // "offSoundSignal"
QT_MOC_LITERAL(5, 48, 13), // "onSoundSignal"
QT_MOC_LITERAL(6, 62, 11), // "loginSignal"
QT_MOC_LITERAL(7, 74, 9), // "outSignal"
QT_MOC_LITERAL(8, 84, 11), // "onButSignal"
QT_MOC_LITERAL(9, 96, 12), // "offButSignal"
QT_MOC_LITERAL(10, 109, 13), // "showButSignal"
QT_MOC_LITERAL(11, 123, 17), // "showHoldButSignal"
QT_MOC_LITERAL(12, 141, 12), // "offSoundSlot"
QT_MOC_LITERAL(13, 154, 11) // "onSoundSlot"

    },
    "PjSipadaptr\0labelChanged\0\0string\0"
    "offSoundSignal\0onSoundSignal\0loginSignal\0"
    "outSignal\0onButSignal\0offButSignal\0"
    "showButSignal\0showHoldButSignal\0"
    "offSoundSlot\0onSoundSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PjSipadaptr[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,
       6,    0,   74,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    0,   76,    2, 0x06 /* Public */,
       9,    0,   77,    2, 0x06 /* Public */,
      10,    0,   78,    2, 0x06 /* Public */,
      11,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   80,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PjSipadaptr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PjSipadaptr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->labelChanged((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->offSoundSignal(); break;
        case 2: _t->onSoundSignal(); break;
        case 3: _t->loginSignal(); break;
        case 4: _t->outSignal(); break;
        case 5: _t->onButSignal(); break;
        case 6: _t->offButSignal(); break;
        case 7: _t->showButSignal(); break;
        case 8: _t->showHoldButSignal(); break;
        case 9: _t->offSoundSlot(); break;
        case 10: _t->onSoundSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PjSipadaptr::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::labelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::offSoundSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::onSoundSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::loginSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::outSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::onButSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::offButSignal)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::showButSignal)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (PjSipadaptr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PjSipadaptr::showHoldButSignal)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PjSipadaptr::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PjSipadaptr.data,
    qt_meta_data_PjSipadaptr,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PjSipadaptr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PjSipadaptr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PjSipadaptr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PjSipadaptr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PjSipadaptr::labelChanged(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PjSipadaptr::offSoundSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PjSipadaptr::onSoundSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PjSipadaptr::loginSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PjSipadaptr::outSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PjSipadaptr::onButSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PjSipadaptr::offButSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void PjSipadaptr::showButSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void PjSipadaptr::showHoldButSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
