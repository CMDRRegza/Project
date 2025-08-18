/****************************************************************************
** Meta object code from reading C++ file 'configmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../configmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configmanager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13ConfigManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto ConfigManager::qt_create_metaobjectdata<qt_meta_tag_ZN13ConfigManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ConfigManager",
        "commanderNameChanged",
        "",
        "journalPathChanged",
        "currentSystemChanged",
        "supabaseUrlChanged",
        "supabaseKeyChanged",
        "supabaseAuthConfirmationChanged",
        "journalVerifiedChanged",
        "isAdminChanged",
        "configLoaded",
        "configError",
        "error",
        "loadConfig",
        "saveConfig",
        "setJournalVerified",
        "verified",
        "commanderName",
        "journalPath",
        "currentSystem",
        "supabaseUrl",
        "supabaseKey",
        "supabaseAuthConfirmation",
        "journalVerified",
        "isAdmin"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'commanderNameChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'journalPathChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentSystemChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'supabaseUrlChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'supabaseKeyChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'supabaseAuthConfirmationChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'journalVerifiedChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isAdminChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'configLoaded'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'configError'
        QtMocHelpers::SignalData<void(const QString &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 },
        }}),
        // Method 'loadConfig'
        QtMocHelpers::MethodData<bool()>(13, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'saveConfig'
        QtMocHelpers::MethodData<bool()>(14, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'setJournalVerified'
        QtMocHelpers::MethodData<void(bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'commanderName'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'journalPath'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'currentSystem'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'supabaseUrl'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
        // property 'supabaseKey'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
        // property 'supabaseAuthConfirmation'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'journalVerified'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags, 6),
        // property 'isAdmin'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags, 7),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ConfigManager, qt_meta_tag_ZN13ConfigManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ConfigManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ConfigManagerE_t>.metaTypes,
    nullptr
} };

void ConfigManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ConfigManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->commanderNameChanged(); break;
        case 1: _t->journalPathChanged(); break;
        case 2: _t->currentSystemChanged(); break;
        case 3: _t->supabaseUrlChanged(); break;
        case 4: _t->supabaseKeyChanged(); break;
        case 5: _t->supabaseAuthConfirmationChanged(); break;
        case 6: _t->journalVerifiedChanged(); break;
        case 7: _t->isAdminChanged(); break;
        case 8: _t->configLoaded(); break;
        case 9: _t->configError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: { bool _r = _t->loadConfig();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->saveConfig();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->setJournalVerified((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::commanderNameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::journalPathChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::currentSystemChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::supabaseUrlChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::supabaseKeyChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::supabaseAuthConfirmationChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::journalVerifiedChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::isAdminChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::configLoaded, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)(const QString & )>(_a, &ConfigManager::configError, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->commanderName(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->journalPath(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->currentSystem(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->supabaseUrl(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->supabaseKey(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->supabaseAuthConfirmation(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->journalVerified(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isAdmin(); break;
        default: break;
        }
    }
}

const QMetaObject *ConfigManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConfigManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ConfigManager::commanderNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ConfigManager::journalPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ConfigManager::currentSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ConfigManager::supabaseUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ConfigManager::supabaseKeyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ConfigManager::supabaseAuthConfirmationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ConfigManager::journalVerifiedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ConfigManager::isAdminChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ConfigManager::configLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ConfigManager::configError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
