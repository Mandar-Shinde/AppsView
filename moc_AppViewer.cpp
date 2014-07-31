/****************************************************************************
** Meta object code from reading C++ file 'AppViewer.h'
**
** Created: Thu Jul 31 11:23:34 2014
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "AppViewer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AppViewer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x08,
      50,   10,   10,   10, 0x08,
      65,   10,   10,   10, 0x08,
      80,   10,   10,   10, 0x08,
      98,   10,   10,   10, 0x08,
     115,   10,   10,   10, 0x08,
     134,   10,   10,   10, 0x08,
     147,   10,   10,   10, 0x08,
     192,  185,   10,   10, 0x08,
     211,   10,   10,   10, 0x08,
     232,  226,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AppViewer[] = {
    "AppViewer\0\0reply\0downloadFinished(QNetworkReply*)\0"
    "slot_setGrid()\0slot_setList()\0"
    "slot_setUniform()\0slot_setSpread()\0"
    "slot_menu_select()\0slot_reset()\0"
    "slot_viewitem_click(QListWidgetItem*)\0"
    "filter\0setFilter(QString)\0slot_Exiting()\0"
    "fname\0slot_updateUI(QString)\0"
};

const QMetaObject AppViewer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AppViewer,
      qt_meta_data_AppViewer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppViewer))
        return static_cast<void*>(const_cast< AppViewer*>(this));
    if (!strcmp(_clname, "TSEAppDialog"))
        return static_cast< TSEAppDialog*>(const_cast< AppViewer*>(this));
    return QDialog::qt_metacast(_clname);
}

int AppViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: slot_setGrid(); break;
        case 2: slot_setList(); break;
        case 3: slot_setUniform(); break;
        case 4: slot_setSpread(); break;
        case 5: slot_menu_select(); break;
        case 6: slot_reset(); break;
        case 7: slot_viewitem_click((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: setFilter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: slot_Exiting(); break;
        case 10: slot_updateUI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
