/****************************************************************************
** Meta object code from reading C++ file 'lines.h'
**
** Created: Wed Apr 10 22:14:44 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lines/view/lines.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Lines[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,    7,    6,    6, 0x0a,
      80,   59,    6,    6, 0x0a,
     109,  103,    6,    6, 0x0a,
     130,  127,    6,    6, 0x0a,
     154,    6,    6,    6, 0x08,
     162,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Lines[] = {
    "Lines\0\0location,busID,busName\0"
    "updateBus(float,int,QString)\0"
    "population,stationID\0updateStation(int,int)\0"
    "busid\0terminateBus(int)\0id\0"
    "updateHighlightVar(int)\0popup()\0send()\0"
};

const QMetaObject Lines::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Lines,
      qt_meta_data_Lines, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Lines::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Lines::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Lines::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Lines))
        return static_cast<void*>(const_cast< Lines*>(this));
    return QWidget::qt_metacast(_clname);
}

int Lines::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateBus((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: updateStation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: terminateBus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: updateHighlightVar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: popup(); break;
        case 5: send(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
