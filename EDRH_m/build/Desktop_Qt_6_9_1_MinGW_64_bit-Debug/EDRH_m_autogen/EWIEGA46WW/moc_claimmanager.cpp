/****************************************************************************
** Meta object code from reading C++ file 'claimmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../claimmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'claimmanager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12ClaimManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto ClaimManager::qt_create_metaobjectdata<qt_meta_tag_ZN12ClaimManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClaimManager",
        "claimStatusChanged",
        "",
        "systemName",
        "isClaimed",
        "claimedBy",
        "systemDoneStatusChanged",
        "isDone",
        "currentClaimChanged",
        "claimError",
        "message",
        "onDatabaseOperationComplete",
        "operation",
        "success",
        "data",
        "onTakenSystemsReceived",
        "taken",
        "canClaimSystem",
        "claimSystem",
        "unclaimSystem",
        "getCurrentClaim",
        "hasActiveClaim",
        "getClaimCount",
        "isSystemCompleted",
        "getSystemClaimedBy",
        "isSystemClaimedByUser",
        "refreshClaimData",
        "getClaimStatusDebug",
        "applyLocalClaim",
        "applyLocalUnclaim"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'claimStatusChanged'
        QtMocHelpers::SignalData<void(const QString &, bool, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 4 }, { QMetaType::QString, 5 },
        }}),
        // Signal 'systemDoneStatusChanged'
        QtMocHelpers::SignalData<void(const QString &, bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::Bool, 7 },
        }}),
        // Signal 'currentClaimChanged'
        QtMocHelpers::SignalData<void(const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'claimError'
        QtMocHelpers::SignalData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Slot 'onDatabaseOperationComplete'
        QtMocHelpers::SlotData<void(const QString &, bool, const QString &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 12 }, { QMetaType::Bool, 13 }, { QMetaType::QString, 14 },
        }}),
        // Slot 'onTakenSystemsReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 16 },
        }}),
        // Method 'canClaimSystem'
        QtMocHelpers::MethodData<bool(const QString &)>(17, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'claimSystem'
        QtMocHelpers::MethodData<bool(const QString &)>(18, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'unclaimSystem'
        QtMocHelpers::MethodData<bool(const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'getCurrentClaim'
        QtMocHelpers::MethodData<QString() const>(20, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'hasActiveClaim'
        QtMocHelpers::MethodData<bool() const>(21, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'getClaimCount'
        QtMocHelpers::MethodData<int() const>(22, 2, QMC::AccessPublic, QMetaType::Int),
        // Method 'isSystemCompleted'
        QtMocHelpers::MethodData<bool(const QString &)>(23, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'getSystemClaimedBy'
        QtMocHelpers::MethodData<QString(const QString &)>(24, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'isSystemClaimedByUser'
        QtMocHelpers::MethodData<bool(const QString &)>(25, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'refreshClaimData'
        QtMocHelpers::MethodData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getClaimStatusDebug'
        QtMocHelpers::MethodData<QString(const QString &)>(27, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'applyLocalClaim'
        QtMocHelpers::MethodData<void(const QString &)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Method 'applyLocalUnclaim'
        QtMocHelpers::MethodData<void(const QString &)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClaimManager, qt_meta_tag_ZN12ClaimManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClaimManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ClaimManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ClaimManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ClaimManagerE_t>.metaTypes,
    nullptr
} };

void ClaimManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClaimManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->claimStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 1: _t->systemDoneStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->currentClaimChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->claimError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->onDatabaseOperationComplete((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->onTakenSystemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 6: { bool _r = _t->canClaimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->claimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->unclaimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getCurrentClaim();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->hasActiveClaim();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getClaimCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->isSystemCompleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->getSystemClaimedBy((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->isSystemClaimedByUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->refreshClaimData(); break;
        case 16: { QString _r = _t->getClaimStatusDebug((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->applyLocalClaim((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->applyLocalUnclaim((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClaimManager::*)(const QString & , bool , const QString & )>(_a, &ClaimManager::claimStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClaimManager::*)(const QString & , bool )>(_a, &ClaimManager::systemDoneStatusChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClaimManager::*)(const QString & )>(_a, &ClaimManager::currentClaimChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClaimManager::*)(const QString & )>(_a, &ClaimManager::claimError, 3))
            return;
    }
}

const QMetaObject *ClaimManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClaimManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ClaimManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClaimManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void ClaimManager::claimStatusChanged(const QString & _t1, bool _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 1
void ClaimManager::systemDoneStatusChanged(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void ClaimManager::currentClaimChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ClaimManager::claimError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
