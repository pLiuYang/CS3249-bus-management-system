/****************************************************************************
** Meta object code from reading C++ file 'StationUpdater.h'
**
** Created: Wed Apr 3 23:54:43 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StationUpdater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StationUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StationUpdater[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      47,   15,   15,   15, 0x08,
      68,   15,   15,   15, 0x08,
      89,   15,   15,   15, 0x08,
     118,   15,   15,   15, 0x08,
     132,   15,   15,   15, 0x08,
     146,   15,   15,   15, 0x08,
     159,   15,   15,   15, 0x08,
     172,   15,   15,   15, 0x08,
     186,   15,   15,   15, 0x08,
     207,  200,   15,   15, 0x08,
     236,  222,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StationUpdater[] = {
    "StationUpdater\0\0updateStation()\0"
    "updateServer()\0updateStationTimer()\0"
    "initialiseStations()\0initialisePeopleAtStations()\0"
    "createBusA1()\0createBusA2()\0createBusB()\0"
    "createBusC()\0createBusD1()\0createBusD2()\0"
    "bus_id\0removeBus(int)\0busID,busName\0"
    "createBus(int,char*)\0"
};

const QMetaObject StationUpdater::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_StationUpdater,
      qt_meta_data_StationUpdater, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StationUpdater::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StationUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StationUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StationUpdater))
        return static_cast<void*>(const_cast< StationUpdater*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int StationUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateStation(); break;
        case 1: updateServer(); break;
        case 2: updateStationTimer(); break;
        case 3: initialiseStations(); break;
        case 4: initialisePeopleAtStations(); break;
        case 5: createBusA1(); break;
        case 6: createBusA2(); break;
        case 7: createBusB(); break;
        case 8: createBusC(); break;
        case 9: createBusD1(); break;
        case 10: createBusD2(); break;
        case 11: removeBus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: createBus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
