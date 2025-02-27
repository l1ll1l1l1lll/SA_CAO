/****************************************************************************
** Meta object code from reading C++ file 'mission_panel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/mission_panel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mission_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_diablo_rviz2_control_plugin__MissionPanel_t {
    QByteArrayData data[19];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_diablo_rviz2_control_plugin__MissionPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_diablo_rviz2_control_plugin__MissionPanel_t qt_meta_stringdata_diablo_rviz2_control_plugin__MissionPanel = {
    {
QT_MOC_LITERAL(0, 0, 41), // "diablo_rviz2_control_plugin::..."
QT_MOC_LITERAL(1, 42, 15), // "trigger_service"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 3), // "msg"
QT_MOC_LITERAL(4, 63, 11), // "std::string"
QT_MOC_LITERAL(5, 75, 12), // "service_name"
QT_MOC_LITERAL(6, 88, 16), // "set_robot_status"
QT_MOC_LITERAL(7, 105, 8), // "set_mode"
QT_MOC_LITERAL(8, 114, 7), // "mode_id"
QT_MOC_LITERAL(9, 122, 3), // "map"
QT_MOC_LITERAL(10, 126, 1), // "x"
QT_MOC_LITERAL(11, 128, 6), // "in_min"
QT_MOC_LITERAL(12, 135, 6), // "in_max"
QT_MOC_LITERAL(13, 142, 7), // "out_min"
QT_MOC_LITERAL(14, 150, 7), // "out_max"
QT_MOC_LITERAL(15, 158, 10), // "set_height"
QT_MOC_LITERAL(16, 169, 6), // "height"
QT_MOC_LITERAL(17, 176, 12), // "set_order_id"
QT_MOC_LITERAL(18, 189, 8) // "order_id"

    },
    "diablo_rviz2_control_plugin::MissionPanel\0"
    "trigger_service\0\0msg\0std::string\0"
    "service_name\0set_robot_status\0set_mode\0"
    "mode_id\0map\0x\0in_min\0in_max\0out_min\0"
    "out_max\0set_height\0height\0set_order_id\0"
    "order_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_diablo_rviz2_control_plugin__MissionPanel[] = {

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
       1,    2,   44,    2, 0x09 /* Protected */,
       6,    1,   49,    2, 0x09 /* Protected */,
       7,    1,   52,    2, 0x09 /* Protected */,
       9,    5,   55,    2, 0x09 /* Protected */,
      15,    1,   66,    2, 0x09 /* Protected */,
      17,    1,   69,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void diablo_rviz2_control_plugin::MissionPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MissionPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trigger_service((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 1: _t->set_robot_status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->set_mode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { float _r = _t->map((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->set_height((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_order_id((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject diablo_rviz2_control_plugin::MissionPanel::staticMetaObject = { {
    &rviz_common::Panel::staticMetaObject,
    qt_meta_stringdata_diablo_rviz2_control_plugin__MissionPanel.data,
    qt_meta_data_diablo_rviz2_control_plugin__MissionPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *diablo_rviz2_control_plugin::MissionPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *diablo_rviz2_control_plugin::MissionPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_diablo_rviz2_control_plugin__MissionPanel.stringdata0))
        return static_cast<void*>(this);
    return rviz_common::Panel::qt_metacast(_clname);
}

int diablo_rviz2_control_plugin::MissionPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz_common::Panel::qt_metacall(_c, _id, _a);
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
