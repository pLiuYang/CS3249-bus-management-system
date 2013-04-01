/****************************************************************************
** Meta object code from reading C++ file 'TripPlanner.h'
**
** Created: Mon Apr 1 19:50:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TripPlanner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TripPlanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TripPlanner[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      35,   28,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   12,   12,   12, 0x0a,
      65,   12,   12,   12, 0x08,
      83,   12,   12,   12, 0x08,
      96,   12,   12,   12, 0x08,
     110,   12,   12,   12, 0x08,
     137,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TripPlanner[] = {
    "TripPlanner\0\0workFinished()\0bus_id\0"
    "removeBus(int)\0startSending()\0"
    "connectToServer()\0stopSearch()\0"
    "sendRequest()\0connectionClosedByServer()\0"
    "error()\0"
};

void TripPlanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TripPlanner *_t = static_cast<TripPlanner *>(_o);
        switch (_id) {
        case 0: _t->workFinished(); break;
        case 1: _t->removeBus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->startSending(); break;
        case 3: _t->connectToServer(); break;
        case 4: _t->stopSearch(); break;
        case 5: _t->sendRequest(); break;
        case 6: _t->connectionClosedByServer(); break;
        case 7: _t->error(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TripPlanner::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TripPlanner::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TripPlanner,
      qt_meta_data_TripPlanner, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TripPlanner::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TripPlanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TripPlanner::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TripPlanner))
        return static_cast<void*>(const_cast< TripPlanner*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TripPlanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TripPlanner::workFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TripPlanner::removeBus(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
