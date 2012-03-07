/****************************************************************************
** Meta object code from reading C++ file 'myglwidget.h'
**
** Created: Wed Mar 7 01:29:12 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myglwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myGLWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      20,   18,   11,   11, 0x0a,
      31,   18,   11,   11, 0x0a,
      42,   18,   11,   11, 0x0a,
      61,   53,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myGLWidget[] = {
    "myGLWidget\0\0run()\0v\0girox(int)\0"
    "giroy(int)\0giroz(int)\0checked\0play(bool)\0"
};

const QMetaObject myGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_myGLWidget,
      qt_meta_data_myGLWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myGLWidget))
        return static_cast<void*>(const_cast< myGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int myGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: run(); break;
        case 1: girox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: giroy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: giroz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: play((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
