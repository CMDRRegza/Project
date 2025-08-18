/****************************************************************************
** Meta object code from reading C++ file 'journalmonitor.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../journalmonitor.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'journalmonitor.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14JournalMonitorE_t {};
} // unnamed namespace

template <> constexpr inline auto JournalMonitor::qt_create_metaobjectdata<qt_meta_tag_ZN14JournalMonitorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "JournalMonitor",
        "commanderNameChanged",
        "",
        "commanderDetected",
        "commanderName",
        "currentSystemChanged",
        "journalPathChanged",
        "isMonitoringChanged",
        "journalUpdated",
        "fsdJumpDetected",
        "system",
        "jumpData",
        "carrierJumpDetected",
        "journalError",
        "error",
        "onFileChanged",
        "path",
        "onDirectoryChanged",
        "checkForUpdates",
        "startMonitoring",
        "stopMonitoring",
        "analyzeJournalFolder",
        "folderPath",
        "autoDetectJournalFolder",
        "getLatestJournalFile",
        "countTotalJumps",
        "extractCommanderFromJournal",
        "journalFilePath",
        "currentSystem",
        "journalPath",
        "isMonitoring"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'commanderNameChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commanderDetected'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'currentSystemChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'journalPathChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isMonitoringChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'journalUpdated'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'fsdJumpDetected'
        QtMocHelpers::SignalData<void(const QString &, const QJsonObject &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QJsonObject, 11 },
        }}),
        // Signal 'carrierJumpDetected'
        QtMocHelpers::SignalData<void(const QString &, const QJsonObject &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QJsonObject, 11 },
        }}),
        // Signal 'journalError'
        QtMocHelpers::SignalData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Slot 'onFileChanged'
        QtMocHelpers::SlotData<void(const QString &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'onDirectoryChanged'
        QtMocHelpers::SlotData<void(const QString &)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'checkForUpdates'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'startMonitoring'
        QtMocHelpers::MethodData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'stopMonitoring'
        QtMocHelpers::MethodData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'analyzeJournalFolder'
        QtMocHelpers::MethodData<bool(const QString &)>(21, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 22 },
        }}),
        // Method 'autoDetectJournalFolder'
        QtMocHelpers::MethodData<QString()>(23, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'getLatestJournalFile'
        QtMocHelpers::MethodData<QString()>(24, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'countTotalJumps'
        QtMocHelpers::MethodData<int() const>(25, 2, QMC::AccessPublic, QMetaType::Int),
        // Method 'extractCommanderFromJournal'
        QtMocHelpers::MethodData<QString(const QString &)>(26, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 27 },
        }}),
        // Method 'extractCommanderFromJournal'
        QtMocHelpers::MethodData<QString()>(26, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'commanderName'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'currentSystem'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'journalPath'
        QtMocHelpers::PropertyData<QString>(29, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'isMonitoring'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<JournalMonitor, qt_meta_tag_ZN14JournalMonitorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject JournalMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14JournalMonitorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14JournalMonitorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14JournalMonitorE_t>.metaTypes,
    nullptr
} };

void JournalMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<JournalMonitor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->commanderNameChanged(); break;
        case 1: _t->commanderDetected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->currentSystemChanged(); break;
        case 3: _t->journalPathChanged(); break;
        case 4: _t->isMonitoringChanged(); break;
        case 5: _t->journalUpdated(); break;
        case 6: _t->fsdJumpDetected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 7: _t->carrierJumpDetected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 8: _t->journalError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onFileChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->onDirectoryChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->checkForUpdates(); break;
        case 12: _t->startMonitoring(); break;
        case 13: _t->stopMonitoring(); break;
        case 14: { bool _r = _t->analyzeJournalFolder((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->autoDetectJournalFolder();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->getLatestJournalFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { int _r = _t->countTotalJumps();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->extractCommanderFromJournal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->extractCommanderFromJournal();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)()>(_a, &JournalMonitor::commanderNameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)(const QString & )>(_a, &JournalMonitor::commanderDetected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)()>(_a, &JournalMonitor::currentSystemChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)()>(_a, &JournalMonitor::journalPathChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)()>(_a, &JournalMonitor::isMonitoringChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)()>(_a, &JournalMonitor::journalUpdated, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)(const QString & , const QJsonObject & )>(_a, &JournalMonitor::fsdJumpDetected, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)(const QString & , const QJsonObject & )>(_a, &JournalMonitor::carrierJumpDetected, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (JournalMonitor::*)(const QString & )>(_a, &JournalMonitor::journalError, 8))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->commanderName(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->currentSystem(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->journalPath(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isMonitoring(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setJournalPath(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *JournalMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JournalMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14JournalMonitorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JournalMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void JournalMonitor::commanderNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void JournalMonitor::commanderDetected(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void JournalMonitor::currentSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void JournalMonitor::journalPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void JournalMonitor::isMonitoringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void JournalMonitor::journalUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void JournalMonitor::fsdJumpDetected(const QString & _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void JournalMonitor::carrierJumpDetected(const QString & _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 8
void JournalMonitor::journalError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP
