/****************************************************************************
** Meta object code from reading C++ file 'lines.h'
**
** Created: Mon Apr 1 20:27:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lines/view/lines.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lines.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Lines[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,    7,    6,    6, 0x0a,
      80,   59,    6,    6, 0x0a,
     109,  103,    6,    6, 0x0a,
     127,    6,    6,    6, 0x08,
     135,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Lines[] = {
    "Lines\0\0location,busID,busName\0"
    "updateBus(float,int,QString)\0"
    "population,stationID\0updateStation(int,int)\0"
    "busid\0terminateBus(int)\0popup()\0send()\0"
};

void Lines::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Lines *_t = static_cast<Lines *>(_o);
        switch (_id) {
        case 0: _t->updateBus((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->updateStation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->terminateBus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->popup(); break;
        case 4: _t->send(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Lines::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Lines::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Lines,
      qt_meta_data_Lines, &staticMetaObjectExtraData }
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
