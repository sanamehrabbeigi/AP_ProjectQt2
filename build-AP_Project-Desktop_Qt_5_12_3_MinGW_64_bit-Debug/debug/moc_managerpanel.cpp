/****************************************************************************
** Meta object code from reading C++ file 'managerpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AP_Project/managerpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managerpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_managerPanel_t {
    QByteArrayData data[11];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_managerPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_managerPanel_t qt_meta_stringdata_managerPanel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "managerPanel"
QT_MOC_LITERAL(1, 13, 23), // "addPictureButtonClicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 31), // "addApartmentCancelButtonClicked"
QT_MOC_LITERAL(4, 70, 25), // "addApartmentButtonClicked"
QT_MOC_LITERAL(5, 96, 24), // "apartmentOkButtonClicked"
QT_MOC_LITERAL(6, 121, 28), // "apartmentFindIDButtonClicked"
QT_MOC_LITERAL(7, 150, 21), // "addHouseButtonClicked"
QT_MOC_LITERAL(8, 172, 26), // "addHouseClearButtonClicked"
QT_MOC_LITERAL(9, 199, 20), // "houseOkButtonClicked"
QT_MOC_LITERAL(10, 220, 24) // "houseFindIDButtonClicked"

    },
    "managerPanel\0addPictureButtonClicked\0"
    "\0addApartmentCancelButtonClicked\0"
    "addApartmentButtonClicked\0"
    "apartmentOkButtonClicked\0"
    "apartmentFindIDButtonClicked\0"
    "addHouseButtonClicked\0addHouseClearButtonClicked\0"
    "houseOkButtonClicked\0houseFindIDButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_managerPanel[] = {

 // content:
       8,       // revision
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

void managerPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<managerPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addPictureButtonClicked(); break;
        case 1: _t->addApartmentCancelButtonClicked(); break;
        case 2: _t->addApartmentButtonClicked(); break;
        case 3: _t->apartmentOkButtonClicked(); break;
        case 4: _t->apartmentFindIDButtonClicked(); break;
        case 5: _t->addHouseButtonClicked(); break;
        case 6: _t->addHouseClearButtonClicked(); break;
        case 7: _t->houseOkButtonClicked(); break;
        case 8: _t->houseFindIDButtonClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject managerPanel::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_managerPanel.data,
    qt_meta_data_managerPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *managerPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *managerPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_managerPanel.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int managerPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
