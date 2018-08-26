/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata0[472];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "readVoltage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "updatePlotData"
QT_MOC_LITERAL(4, 39, 13), // "getADCChannel"
QT_MOC_LITERAL(5, 53, 9), // "ADC_value"
QT_MOC_LITERAL(6, 63, 22), // "PlotChannel_Controller"
QT_MOC_LITERAL(7, 86, 13), // "channel_index"
QT_MOC_LITERAL(8, 100, 7), // "checked"
QT_MOC_LITERAL(9, 108, 13), // "SetCurveColor"
QT_MOC_LITERAL(10, 122, 5), // "color"
QT_MOC_LITERAL(11, 128, 26), // "on_SerialRunButton_clicked"
QT_MOC_LITERAL(12, 155, 21), // "on_QuitButton_clicked"
QT_MOC_LITERAL(13, 177, 25), // "on_MaxVoltEdit_textEdited"
QT_MOC_LITERAL(14, 203, 4), // "arg1"
QT_MOC_LITERAL(15, 208, 25), // "on_MinVoltEdit_textEdited"
QT_MOC_LITERAL(16, 234, 32), // "on_TimeRangespinBox_valueChanged"
QT_MOC_LITERAL(17, 267, 30), // "on_SerialConnectButton_clicked"
QT_MOC_LITERAL(18, 298, 31), // "on_SamplingTimeEdit_textChanged"
QT_MOC_LITERAL(19, 330, 23), // "on_checkBox_CH0_clicked"
QT_MOC_LITERAL(20, 354, 23), // "on_checkBox_CH1_clicked"
QT_MOC_LITERAL(21, 378, 23), // "on_checkBox_CH2_clicked"
QT_MOC_LITERAL(22, 402, 31), // "on_YPositionSlider_valueChanged"
QT_MOC_LITERAL(23, 434, 5), // "value"
QT_MOC_LITERAL(24, 440, 31) // "on_XPositionSlider_valueChanged"

    },
    "MainWindow\0readVoltage\0\0updatePlotData\0"
    "getADCChannel\0ADC_value\0PlotChannel_Controller\0"
    "channel_index\0checked\0SetCurveColor\0"
    "color\0on_SerialRunButton_clicked\0"
    "on_QuitButton_clicked\0on_MaxVoltEdit_textEdited\0"
    "arg1\0on_MinVoltEdit_textEdited\0"
    "on_TimeRangespinBox_valueChanged\0"
    "on_SerialConnectButton_clicked\0"
    "on_SamplingTimeEdit_textChanged\0"
    "on_checkBox_CH0_clicked\0on_checkBox_CH1_clicked\0"
    "on_checkBox_CH2_clicked\0"
    "on_YPositionSlider_valueChanged\0value\0"
    "on_XPositionSlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    1,  101,    2, 0x08 /* Private */,
       6,    2,  104,    2, 0x08 /* Private */,
       9,    1,  109,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    0,  113,    2, 0x08 /* Private */,
      13,    1,  114,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      16,    1,  120,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,
      18,    1,  124,    2, 0x08 /* Private */,
      19,    1,  127,    2, 0x08 /* Private */,
      20,    1,  130,    2, 0x08 /* Private */,
      21,    1,  133,    2, 0x08 /* Private */,
      22,    1,  136,    2, 0x08 /* Private */,
      24,    1,  139,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Char, QMetaType::UChar,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::QColor, QMetaType::UChar,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readVoltage(); break;
        case 1: _t->updatePlotData(); break;
        case 2: { char _r = _t->getADCChannel((*reinterpret_cast< unsigned char(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< char*>(_a[0]) = _r; }  break;
        case 3: _t->PlotChannel_Controller((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: { QColor _r = _t->SetCurveColor((*reinterpret_cast< unsigned char(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 5: _t->on_SerialRunButton_clicked(); break;
        case 6: _t->on_QuitButton_clicked(); break;
        case 7: _t->on_MaxVoltEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_MinVoltEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_TimeRangespinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_SerialConnectButton_clicked(); break;
        case 11: _t->on_SamplingTimeEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_checkBox_CH0_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_checkBox_CH1_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_checkBox_CH2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_YPositionSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_XPositionSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
