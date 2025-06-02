/****************************************************************************
** Meta object code from reading C++ file 'teleop_button.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/teleop_button.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teleop_button.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_diablo_rviz2_control_plugin__TeleopButton_t {
    QByteArrayData data[11];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_diablo_rviz2_control_plugin__TeleopButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_diablo_rviz2_control_plugin__TeleopButton_t qt_meta_stringdata_diablo_rviz2_control_plugin__TeleopButton = {
    {
QT_MOC_LITERAL(0, 0, 41), // "diablo_rviz2_control_plugin::..."
QT_MOC_LITERAL(1, 42, 8), // "setTopic"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 5), // "topic"
QT_MOC_LITERAL(4, 58, 15), // "discover_topics"
QT_MOC_LITERAL(5, 74, 12), // "update_topic"
QT_MOC_LITERAL(6, 87, 3), // "pos"
QT_MOC_LITERAL(7, 91, 16), // "set_linear_speed"
QT_MOC_LITERAL(8, 108, 5), // "value"
QT_MOC_LITERAL(9, 114, 17), // "set_angular_speed"
QT_MOC_LITERAL(10, 132, 12) // "restore_pose"

    },
    "diablo_rviz2_control_plugin::TeleopButton\0"
    "setTopic\0\0topic\0discover_topics\0"
    "update_topic\0pos\0set_linear_speed\0"
    "value\0set_angular_speed\0restore_pose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_diablo_rviz2_control_plugin__TeleopButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    1,   48,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
       9,    1,   54,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,

       0        // eod
};

void diablo_rviz2_control_plugin::TeleopButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TeleopButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTopic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->discover_topics(); break;
        case 2: _t->update_topic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->set_linear_speed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_angular_speed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->restore_pose(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject diablo_rviz2_control_plugin::TeleopButton::staticMetaObject = { {
    &QGridLayout::staticMetaObject,
    qt_meta_stringdata_diablo_rviz2_control_plugin__TeleopButton.data,
    qt_meta_data_diablo_rviz2_control_plugin__TeleopButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *diablo_rviz2_control_plugin::TeleopButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *diablo_rviz2_control_plugin::TeleopButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_diablo_rviz2_control_plugin__TeleopButton.stringdata0))
        return static_cast<void*>(this);
    return QGridLayout::qt_metacast(_clname);
}

int diablo_rviz2_control_plugin::TeleopButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
