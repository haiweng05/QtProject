/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Project/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 22), // "handleSelectionChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 6), // "Submit"
QT_MOC_LITERAL(4, 42, 11), // "ClassImport"
QT_MOC_LITERAL(5, 54, 11), // "ClassModify"
QT_MOC_LITERAL(6, 66, 11), // "Personalize"
QT_MOC_LITERAL(7, 78, 6), // "oneday"
QT_MOC_LITERAL(8, 85, 4), // "date"
QT_MOC_LITERAL(9, 90, 26), // "onItemContextMenuRequested"
QT_MOC_LITERAL(10, 117, 3), // "pos"
QT_MOC_LITERAL(11, 121, 23), // "onActiondeleteTriggered"
QT_MOC_LITERAL(12, 145, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(13, 163, 4), // "item"
QT_MOC_LITERAL(14, 168, 20), // "onActionaddTriggered"
QT_MOC_LITERAL(15, 189, 23), // "onActioncancelTriggered"
QT_MOC_LITERAL(16, 213, 23), // "onActionreviseTriggered"
QT_MOC_LITERAL(17, 237, 17), // "updateTimeDisplay"
QT_MOC_LITERAL(18, 255, 13), // "AddActivities"
QT_MOC_LITERAL(19, 269, 16), // "onButton1Clicked"
QT_MOC_LITERAL(20, 286, 16), // "onButton2Clicked"
QT_MOC_LITERAL(21, 303, 16) // "onButton3Clicked"

    },
    "MainWindow\0handleSelectionChanged\0\0"
    "Submit\0ClassImport\0ClassModify\0"
    "Personalize\0oneday\0date\0"
    "onItemContextMenuRequested\0pos\0"
    "onActiondeleteTriggered\0QTableWidgetItem*\0"
    "item\0onActionaddTriggered\0"
    "onActioncancelTriggered\0onActionreviseTriggered\0"
    "updateTimeDisplay\0AddActivities\0"
    "onButton1Clicked\0onButton2Clicked\0"
    "onButton3Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
       9,    1,  102,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    1,  109,    2, 0x08 /* Private */,
      16,    1,  112,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,
      20,    0,  118,    2, 0x08 /* Private */,
      21,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    8,
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleSelectionChanged(); break;
        case 1: _t->Submit(); break;
        case 2: _t->ClassImport(); break;
        case 3: _t->ClassModify(); break;
        case 4: _t->Personalize(); break;
        case 5: _t->oneday((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 6: _t->onItemContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->onActiondeleteTriggered((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->onActionaddTriggered(); break;
        case 9: _t->onActioncancelTriggered((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->onActionreviseTriggered((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->updateTimeDisplay(); break;
        case 12: _t->AddActivities(); break;
        case 13: _t->onButton1Clicked(); break;
        case 14: _t->onButton2Clicked(); break;
        case 15: _t->onButton3Clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
