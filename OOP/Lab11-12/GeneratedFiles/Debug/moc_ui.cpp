/****************************************************************************
** Meta object code from reading C++ file 'ui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UI_t {
    QByteArrayData data[14];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UI_t qt_meta_stringdata_UI = {
    {
QT_MOC_LITERAL(0, 0, 2), // "UI"
QT_MOC_LITERAL(1, 3, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "addNewMovie"
QT_MOC_LITERAL(4, 32, 11), // "deleteMovie"
QT_MOC_LITERAL(5, 44, 16), // "updateRepoMovies"
QT_MOC_LITERAL(6, 61, 16), // "filterRepoMovies"
QT_MOC_LITERAL(7, 78, 20), // "moveMovieToWatchlist"
QT_MOC_LITERAL(8, 99, 13), // "moveAllMovies"
QT_MOC_LITERAL(9, 113, 12), // "watchTrailer"
QT_MOC_LITERAL(10, 126, 13), // "deleteWatched"
QT_MOC_LITERAL(11, 140, 8), // "openFile"
QT_MOC_LITERAL(12, 149, 4), // "undo"
QT_MOC_LITERAL(13, 154, 13) // "showWatchlist"

    },
    "UI\0listItemChanged\0\0addNewMovie\0"
    "deleteMovie\0updateRepoMovies\0"
    "filterRepoMovies\0moveMovieToWatchlist\0"
    "moveAllMovies\0watchTrailer\0deleteWatched\0"
    "openFile\0undo\0showWatchlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UI *_t = static_cast<UI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->addNewMovie(); break;
        case 2: _t->deleteMovie(); break;
        case 3: _t->updateRepoMovies(); break;
        case 4: _t->filterRepoMovies(); break;
        case 5: _t->moveMovieToWatchlist(); break;
        case 6: _t->moveAllMovies(); break;
        case 7: _t->watchTrailer(); break;
        case 8: _t->deleteWatched(); break;
        case 9: _t->openFile(); break;
        case 10: _t->undo(); break;
        case 11: _t->showWatchlist(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UI.data,
      qt_meta_data_UI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UI.stringdata0))
        return static_cast<void*>(const_cast< UI*>(this));
    return QWidget::qt_metacast(_clname);
}

int UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
