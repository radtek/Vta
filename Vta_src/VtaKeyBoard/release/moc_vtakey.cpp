/****************************************************************************
** Meta object code from reading C++ file 'vtakey.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vtakey.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vtakey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VtaKey_t {
    QByteArrayData data[8];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VtaKey_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VtaKey_t qt_meta_stringdata_VtaKey = {
    {
QT_MOC_LITERAL(0, 0, 6), // "VtaKey"
QT_MOC_LITERAL(1, 7, 16), // "insertCompletion"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "completion"
QT_MOC_LITERAL(4, 36, 13), // "modelFromFile"
QT_MOC_LITERAL(5, 50, 19), // "QAbstractItemModel*"
QT_MOC_LITERAL(6, 70, 8), // "fileName"
QT_MOC_LITERAL(7, 79, 6) // "NewStr"

    },
    "VtaKey\0insertCompletion\0\0completion\0"
    "modelFromFile\0QAbstractItemModel*\0"
    "fileName\0NewStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VtaKey[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    2,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    0x80000000 | 5, QMetaType::QString, QMetaType::QString,    6,    7,

       0        // eod
};

void VtaKey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VtaKey *_t = static_cast<VtaKey *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insertCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: { QAbstractItemModel* _r = _t->modelFromFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QAbstractItemModel**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject VtaKey::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_VtaKey.data,
      qt_meta_data_VtaKey,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VtaKey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VtaKey::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VtaKey.stringdata0))
        return static_cast<void*>(const_cast< VtaKey*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int VtaKey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
