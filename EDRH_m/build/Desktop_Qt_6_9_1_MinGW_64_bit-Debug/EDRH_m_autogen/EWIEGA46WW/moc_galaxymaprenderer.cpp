/****************************************************************************
** Meta object code from reading C++ file 'galaxymaprenderer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../galaxymaprenderer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'galaxymaprenderer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN17GalaxyMapRendererE_t {};
} // unnamed namespace

template <> constexpr inline auto GalaxyMapRenderer::qt_create_metaobjectdata<qt_meta_tag_ZN17GalaxyMapRendererE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "GalaxyMapRenderer",
        "zoomLevelChanged",
        "",
        "panOffsetChanged",
        "backgroundImageChanged",
        "starSystemsChanged",
        "showMainSequenceChanged",
        "showNeutronStarsChanged",
        "showWhiteDwarfsChanged",
        "showBlackHolesChanged",
        "tooltipsEnabledChanged",
        "hoveredSystemChanged",
        "commanderPositionChanged",
        "allCommanderLocationsChanged",
        "showAllCommandersChanged",
        "isAdminModeChanged",
        "systemRightClicked",
        "systemName",
        "x",
        "y",
        "z",
        "zoomLevel",
        "panOffset",
        "backgroundImage",
        "starSystems",
        "QVariantList",
        "showMainSequence",
        "showNeutronStars",
        "showWhiteDwarfs",
        "showBlackHoles",
        "tooltipsEnabled",
        "hoveredSystem",
        "commanderPosition",
        "allCommanderLocations",
        "showAllCommanders",
        "isAdminMode"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'zoomLevelChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'panOffsetChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'backgroundImageChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'starSystemsChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showMainSequenceChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showNeutronStarsChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showWhiteDwarfsChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showBlackHolesChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'tooltipsEnabledChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hoveredSystemChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commanderPositionChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'allCommanderLocationsChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showAllCommandersChanged'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isAdminModeChanged'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'systemRightClicked'
        QtMocHelpers::SignalData<void(const QString &, qreal, qreal, qreal)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 17 }, { QMetaType::QReal, 18 }, { QMetaType::QReal, 19 }, { QMetaType::QReal, 20 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'zoomLevel'
        QtMocHelpers::PropertyData<qreal>(21, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'panOffset'
        QtMocHelpers::PropertyData<QPointF>(22, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'backgroundImage'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'starSystems'
        QtMocHelpers::PropertyData<QVariantList>(24, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'showMainSequence'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'showNeutronStars'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'showWhiteDwarfs'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'showBlackHoles'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'tooltipsEnabled'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'hoveredSystem'
        QtMocHelpers::PropertyData<QObject*>(31, QMetaType::QObjectStar, QMC::DefaultPropertyFlags, 9),
        // property 'commanderPosition'
        QtMocHelpers::PropertyData<QPointF>(32, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'allCommanderLocations'
        QtMocHelpers::PropertyData<QVariantList>(33, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 11),
        // property 'showAllCommanders'
        QtMocHelpers::PropertyData<bool>(34, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 12),
        // property 'isAdminMode'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<GalaxyMapRenderer, qt_meta_tag_ZN17GalaxyMapRendererE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject GalaxyMapRenderer::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17GalaxyMapRendererE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17GalaxyMapRendererE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17GalaxyMapRendererE_t>.metaTypes,
    nullptr
} };

void GalaxyMapRenderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<GalaxyMapRenderer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->zoomLevelChanged(); break;
        case 1: _t->panOffsetChanged(); break;
        case 2: _t->backgroundImageChanged(); break;
        case 3: _t->starSystemsChanged(); break;
        case 4: _t->showMainSequenceChanged(); break;
        case 5: _t->showNeutronStarsChanged(); break;
        case 6: _t->showWhiteDwarfsChanged(); break;
        case 7: _t->showBlackHolesChanged(); break;
        case 8: _t->tooltipsEnabledChanged(); break;
        case 9: _t->hoveredSystemChanged(); break;
        case 10: _t->commanderPositionChanged(); break;
        case 11: _t->allCommanderLocationsChanged(); break;
        case 12: _t->showAllCommandersChanged(); break;
        case 13: _t->isAdminModeChanged(); break;
        case 14: _t->systemRightClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::zoomLevelChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::panOffsetChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::backgroundImageChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::starSystemsChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::showMainSequenceChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::showNeutronStarsChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::showWhiteDwarfsChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::showBlackHolesChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::tooltipsEnabledChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::hoveredSystemChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::commanderPositionChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::allCommanderLocationsChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::showAllCommandersChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)()>(_a, &GalaxyMapRenderer::isAdminModeChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (GalaxyMapRenderer::*)(const QString & , qreal , qreal , qreal )>(_a, &GalaxyMapRenderer::systemRightClicked, 14))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qreal*>(_v) = _t->zoomLevel(); break;
        case 1: *reinterpret_cast<QPointF*>(_v) = _t->panOffset(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->backgroundImage(); break;
        case 3: *reinterpret_cast<QVariantList*>(_v) = _t->starSystems(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->showMainSequence(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->showNeutronStars(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->showWhiteDwarfs(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->showBlackHoles(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->tooltipsEnabled(); break;
        case 9: *reinterpret_cast<QObject**>(_v) = _t->hoveredSystem(); break;
        case 10: *reinterpret_cast<QPointF*>(_v) = _t->commanderPosition(); break;
        case 11: *reinterpret_cast<QVariantList*>(_v) = _t->allCommanderLocations(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->showAllCommanders(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->isAdminMode(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setZoomLevel(*reinterpret_cast<qreal*>(_v)); break;
        case 1: _t->setPanOffset(*reinterpret_cast<QPointF*>(_v)); break;
        case 2: _t->setBackgroundImage(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setStarSystems(*reinterpret_cast<QVariantList*>(_v)); break;
        case 4: _t->setShowMainSequence(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setShowNeutronStars(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setShowWhiteDwarfs(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setShowBlackHoles(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setTooltipsEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setCommanderPosition(*reinterpret_cast<QPointF*>(_v)); break;
        case 11: _t->setAllCommanderLocations(*reinterpret_cast<QVariantList*>(_v)); break;
        case 12: _t->setShowAllCommanders(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setIsAdminMode(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *GalaxyMapRenderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GalaxyMapRenderer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17GalaxyMapRendererE_t>.strings))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int GalaxyMapRenderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void GalaxyMapRenderer::zoomLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GalaxyMapRenderer::panOffsetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GalaxyMapRenderer::backgroundImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GalaxyMapRenderer::starSystemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GalaxyMapRenderer::showMainSequenceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GalaxyMapRenderer::showNeutronStarsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void GalaxyMapRenderer::showWhiteDwarfsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void GalaxyMapRenderer::showBlackHolesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void GalaxyMapRenderer::tooltipsEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void GalaxyMapRenderer::hoveredSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void GalaxyMapRenderer::commanderPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GalaxyMapRenderer::allCommanderLocationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void GalaxyMapRenderer::showAllCommandersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void GalaxyMapRenderer::isAdminModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void GalaxyMapRenderer::systemRightClicked(const QString & _t1, qreal _t2, qreal _t3, qreal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1, _t2, _t3, _t4);
}
QT_WARNING_POP
