/****************************************************************************
** Meta object code from reading C++ file 'recordmimicry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../recordmimicry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recordmimicry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RecordMimicry_t {
    QByteArrayData data[11];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecordMimicry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecordMimicry_t qt_meta_stringdata_RecordMimicry = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RecordMimicry"
QT_MOC_LITERAL(1, 14, 11), // "startRecord"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "stopRecord"
QT_MOC_LITERAL(4, 38, 16), // "startCalibration"
QT_MOC_LITERAL(5, 55, 11), // "modeChanged"
QT_MOC_LITERAL(6, 67, 16), // "outputFileDialog"
QT_MOC_LITERAL(7, 84, 21), // "displayOptionsChanged"
QT_MOC_LITERAL(8, 106, 14), // "captureProcess"
QT_MOC_LITERAL(9, 121, 18), // "calibrationProcess"
QT_MOC_LITERAL(10, 140, 29) // "calibrationInformationProcess"

    },
    "RecordMimicry\0startRecord\0\0stopRecord\0"
    "startCalibration\0modeChanged\0"
    "outputFileDialog\0displayOptionsChanged\0"
    "captureProcess\0calibrationProcess\0"
    "calibrationInformationProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecordMimicry[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RecordMimicry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecordMimicry *_t = static_cast<RecordMimicry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startRecord(); break;
        case 1: _t->stopRecord(); break;
        case 2: _t->startCalibration(); break;
        case 3: _t->modeChanged(); break;
        case 4: _t->outputFileDialog(); break;
        case 5: _t->displayOptionsChanged(); break;
        case 6: _t->captureProcess(); break;
        case 7: _t->calibrationProcess(); break;
        case 8: _t->calibrationInformationProcess(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject RecordMimicry::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RecordMimicry.data,
      qt_meta_data_RecordMimicry,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RecordMimicry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecordMimicry::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RecordMimicry.stringdata0))
        return static_cast<void*>(const_cast< RecordMimicry*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RecordMimicry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
