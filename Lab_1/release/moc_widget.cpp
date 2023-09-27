/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../L1/widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "Color",
    "",
    "color",
    "Names_For_LeftLabels",
    "text",
    "Names_For_MidLabels",
    "Names_For_RightLabels",
    "getValues",
    "QList<int>",
    "space_name",
    "value_id",
    "SetColor",
    "a",
    "b",
    "c",
    "d",
    "setSpacesAndLabel",
    "setColorLabel",
    "setSpinBoxes",
    "valuesLeft",
    "valuesMid",
    "valuesRight",
    "setSliders",
    "setSpinsAndLabel",
    "paintEvent",
    "QPaintEvent*",
    "event",
    "slidersMoved",
    "arg",
    "spinsChanged",
    "colorSelection",
    "RGB_To_XYZ",
    "XYZ_To_LAB",
    "XYZ_To_RGB",
    "LAB_To_XYZ"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[72];
    char stringdata0[7];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[21];
    char stringdata5[5];
    char stringdata6[20];
    char stringdata7[22];
    char stringdata8[10];
    char stringdata9[11];
    char stringdata10[11];
    char stringdata11[9];
    char stringdata12[9];
    char stringdata13[2];
    char stringdata14[2];
    char stringdata15[2];
    char stringdata16[2];
    char stringdata17[18];
    char stringdata18[14];
    char stringdata19[13];
    char stringdata20[11];
    char stringdata21[10];
    char stringdata22[12];
    char stringdata23[11];
    char stringdata24[17];
    char stringdata25[11];
    char stringdata26[13];
    char stringdata27[6];
    char stringdata28[13];
    char stringdata29[4];
    char stringdata30[13];
    char stringdata31[15];
    char stringdata32[11];
    char stringdata33[11];
    char stringdata34[11];
    char stringdata35[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 5),  // "Color"
        QT_MOC_LITERAL(13, 0),  // ""
        QT_MOC_LITERAL(14, 5),  // "color"
        QT_MOC_LITERAL(20, 20),  // "Names_For_LeftLabels"
        QT_MOC_LITERAL(41, 4),  // "text"
        QT_MOC_LITERAL(46, 19),  // "Names_For_MidLabels"
        QT_MOC_LITERAL(66, 21),  // "Names_For_RightLabels"
        QT_MOC_LITERAL(88, 9),  // "getValues"
        QT_MOC_LITERAL(98, 10),  // "QList<int>"
        QT_MOC_LITERAL(109, 10),  // "space_name"
        QT_MOC_LITERAL(120, 8),  // "value_id"
        QT_MOC_LITERAL(129, 8),  // "SetColor"
        QT_MOC_LITERAL(138, 1),  // "a"
        QT_MOC_LITERAL(140, 1),  // "b"
        QT_MOC_LITERAL(142, 1),  // "c"
        QT_MOC_LITERAL(144, 1),  // "d"
        QT_MOC_LITERAL(146, 17),  // "setSpacesAndLabel"
        QT_MOC_LITERAL(164, 13),  // "setColorLabel"
        QT_MOC_LITERAL(178, 12),  // "setSpinBoxes"
        QT_MOC_LITERAL(191, 10),  // "valuesLeft"
        QT_MOC_LITERAL(202, 9),  // "valuesMid"
        QT_MOC_LITERAL(212, 11),  // "valuesRight"
        QT_MOC_LITERAL(224, 10),  // "setSliders"
        QT_MOC_LITERAL(235, 16),  // "setSpinsAndLabel"
        QT_MOC_LITERAL(252, 10),  // "paintEvent"
        QT_MOC_LITERAL(263, 12),  // "QPaintEvent*"
        QT_MOC_LITERAL(276, 5),  // "event"
        QT_MOC_LITERAL(282, 12),  // "slidersMoved"
        QT_MOC_LITERAL(295, 3),  // "arg"
        QT_MOC_LITERAL(299, 12),  // "spinsChanged"
        QT_MOC_LITERAL(312, 14),  // "colorSelection"
        QT_MOC_LITERAL(327, 10),  // "RGB_To_XYZ"
        QT_MOC_LITERAL(338, 10),  // "XYZ_To_LAB"
        QT_MOC_LITERAL(349, 10),  // "XYZ_To_RGB"
        QT_MOC_LITERAL(360, 10)   // "LAB_To_XYZ"
    },
    "Widget",
    "Color",
    "",
    "color",
    "Names_For_LeftLabels",
    "text",
    "Names_For_MidLabels",
    "Names_For_RightLabels",
    "getValues",
    "QList<int>",
    "space_name",
    "value_id",
    "SetColor",
    "a",
    "b",
    "c",
    "d",
    "setSpacesAndLabel",
    "setColorLabel",
    "setSpinBoxes",
    "valuesLeft",
    "valuesMid",
    "valuesRight",
    "setSliders",
    "setSpinsAndLabel",
    "paintEvent",
    "QPaintEvent*",
    "event",
    "slidersMoved",
    "arg",
    "spinsChanged",
    "colorSelection",
    "RGB_To_XYZ",
    "XYZ_To_LAB",
    "XYZ_To_RGB",
    "LAB_To_XYZ"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,  137,    2, 0x0a,    3 /* Public */,
       6,    1,  140,    2, 0x0a,    5 /* Public */,
       7,    1,  143,    2, 0x0a,    7 /* Public */,
       8,    1,  146,    2, 0x0a,    9 /* Public */,
      12,    5,  149,    2, 0x0a,   11 /* Public */,
      12,    4,  160,    2, 0x2a,   17 /* Public | MethodCloned */,
      17,    0,  169,    2, 0x0a,   22 /* Public */,
      18,    0,  170,    2, 0x0a,   23 /* Public */,
      19,    3,  171,    2, 0x0a,   24 /* Public */,
      23,    1,  178,    2, 0x0a,   28 /* Public */,
      24,    0,  181,    2, 0x0a,   30 /* Public */,
      25,    1,  182,    2, 0x0a,   31 /* Public */,
      28,    1,  185,    2, 0x0a,   33 /* Public */,
      30,    1,  188,    2, 0x0a,   35 /* Public */,
      31,    0,  191,    2, 0x0a,   37 /* Public */,
      32,    1,  192,    2, 0x0a,   38 /* Public */,
      33,    1,  195,    2, 0x0a,   40 /* Public */,
      34,    1,  198,    2, 0x0a,   42 /* Public */,
      35,    1,  201,    2, 0x0a,   44 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    0x80000000 | 9, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   13,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9,   20,   21,   22,
    QMetaType::Void, 0x80000000 | 9,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Double,   29,
    QMetaType::Double, QMetaType::Double,   29,
    QMetaType::Double, QMetaType::Double,   29,
    QMetaType::Double, QMetaType::Double,   29,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'Color'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>,
        // method 'Names_For_LeftLabels'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Names_For_MidLabels'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Names_For_RightLabels'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getValues'
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<space_name, std::false_type>,
        // method 'SetColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<space_name, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SetColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<space_name, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setSpacesAndLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setColorLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSpinBoxes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        // method 'setSliders'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>,
        // method 'setSpinsAndLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'paintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>,
        // method 'slidersMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'spinsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'colorSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RGB_To_XYZ'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'XYZ_To_LAB'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'XYZ_To_RGB'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'LAB_To_XYZ'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Color((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 1: _t->Names_For_LeftLabels((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->Names_For_MidLabels((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->Names_For_RightLabels((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: { QList<int> _r = _t->getValues((*reinterpret_cast< std::add_pointer_t<space_name>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->SetColor((*reinterpret_cast< std::add_pointer_t<space_name>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 6: _t->SetColor((*reinterpret_cast< std::add_pointer_t<space_name>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 7: _t->setSpacesAndLabel(); break;
        case 8: _t->setColorLabel(); break;
        case 9: _t->setSpinBoxes((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3]))); break;
        case 10: _t->setSliders((*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[1]))); break;
        case 11: _t->setSpinsAndLabel(); break;
        case 12: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        case 13: _t->slidersMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->spinsChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->colorSelection(); break;
        case 16: { double _r = _t->RGB_To_XYZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 17: { double _r = _t->XYZ_To_LAB((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 18: { double _r = _t->XYZ_To_RGB((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 19: { double _r = _t->LAB_To_XYZ((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(QColor );
            if (_t _q_method = &Widget::Color; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Widget::Color(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
