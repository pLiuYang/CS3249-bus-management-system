/****************************************************************************
** Meta object code from reading C++ file 'NumberOfPeopleUpdate.h'
**
** Created: Sat Mar 30 15:04:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "NumberOfPeopleUpdate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NumberOfPeopleUpdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NumberOfPeopleUpdate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   21,   21,   21, 0x0a,
      55,   21,   21,   21, 0x08,
      68,   21,   21,   21, 0x08,
      82,   21,   21,   21, 0x08,
     109,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NumberOfPeopleUpdate[] = {
    "NumberOfPeopleUpdate\0\0workFinished()\0"
    "connectToServer()\0stopSearch()\0"
    "sendRequest()\0connectionClosedByServer()\0"
    "error()\0"
};

void NumberOfPeopleUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NumberOfPeopleUpdate *_t = static_cast<NumberOfPeopleUpdate *>(_o);
        switch (_id) {
        case 0: _t->workFinished(); break;
        case 1: _t->connectToServer(); break;
        case 2: _t->stopSearch(); break;
        case 3: _t->sendRequest(); break;
        case 4: _t->connectionClosedByServer(); break;
        case 5: _t->error(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NumberOfPeopleUpdate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NumberOfPeopleUpdate::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_NumberOfPeopleUpdate,
      qt_meta_data_NumberOfPeopleUpdate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NumberOfPeopleUpdate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NumberOfPeopleUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NumberOfPeopleUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NumberOfPeopleUpdate))
        return static_cast<void*>(const_cast< NumberOfPeopleUpdate*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int NumberOfPeopleUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void NumberOfPeopleUpdate::workFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
