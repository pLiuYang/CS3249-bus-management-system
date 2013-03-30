/****************************************************************************
** Meta object code from reading C++ file 'StationUpdater.h'
**
** Created: Sat Mar 30 15:04:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "StationUpdater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StationUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StationUpdater[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      53,   15,   15,   15, 0x08,
      74,   15,   15,   15, 0x08,
     103,   15,   15,   15, 0x08,
     117,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StationUpdater[] = {
    "StationUpdater\0\0updateStation()\0"
    "updateStationTimer()\0initialiseStations()\0"
    "initialisePeopleAtStations()\0createBusA1()\0"
    "createBusA2()\0"
};

void StationUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StationUpdater *_t = static_cast<StationUpdater *>(_o);
        switch (_id) {
        case 0: _t->updateStation(); break;
        case 1: _t->updateStationTimer(); break;
        case 2: _t->initialiseStations(); break;
        case 3: _t->initialisePeopleAtStations(); break;
        case 4: _t->createBusA1(); break;
        case 5: _t->createBusA2(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData StationUpdater::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StationUpdater::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StationUpdater,
      qt_meta_data_StationUpdater, &staticMetaObjectExtraData }
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
    return QObject::qt_metacast(_clname);
}

int StationUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
