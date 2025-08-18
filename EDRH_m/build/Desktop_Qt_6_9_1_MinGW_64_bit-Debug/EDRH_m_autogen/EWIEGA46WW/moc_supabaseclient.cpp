/****************************************************************************
** Meta object code from reading C++ file 'supabaseclient.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../supabaseclient.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supabaseclient.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14SupabaseClientE_t {};
} // unnamed namespace

template <> constexpr inline auto SupabaseClient::qt_create_metaobjectdata<qt_meta_tag_ZN14SupabaseClientE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SupabaseClient",
        "systemsReceived",
        "",
        "systems",
        "takenSystemsReceived",
        "taken",
        "poisReceived",
        "pois",
        "categoriesReceived",
        "categories",
        "presetImagesReceived",
        "presetImages",
        "nearestSystemsReceived",
        "systemInformationReceived",
        "systemName",
        "systemInfo",
        "systemClaimed",
        "success",
        "systemUnclaimed",
        "systemMarkedVisited",
        "systemStatusUpdated",
        "adminStatusReceived",
        "isAdmin",
        "adminAccessTestComplete",
        "hasAccess",
        "presetImageFound",
        "imageUrl",
        "category",
        "systemImageSet",
        "bulkSystemImagesLoaded",
        "systemImages",
        "allCommanderLocationsReceived",
        "locations",
        "commanderLocationUpdated",
        "commanderName",
        "webhookConfigReceived",
        "webhookUrl",
        "webhookTriggered",
        "eventType",
        "poiDataForMergeReceived",
        "poiData",
        "networkError",
        "error",
        "requestCompleted",
        "operation",
        "message",
        "databaseSyncStatusChanged",
        "status",
        "databaseSyncProgress",
        "current",
        "total",
        "databaseSyncComplete",
        "isFirstRun",
        "changesDetected",
        "securityCheckComplete",
        "isBlocked",
        "reason",
        "authenticationRequired",
        "authenticationComplete",
        "confirmationRequired",
        "title",
        "performSecurityCheck",
        "handleNewCommander",
        "allCommanders",
        "detectCommanderRenames",
        "journalPath",
        "logLoginEvent",
        "details",
        "isCommanderBlocked",
        "addCommanderToSecurity",
        "blocked",
        "notes",
        "handleNetworkReply",
        "QNetworkReply*",
        "reply",
        "configure",
        "url",
        "key",
        "isConfigured",
        "setCommanderContext",
        "getSystems",
        "getTakenSystems",
        "getCurrentCommanderSystems",
        "getPOISystems",
        "getCategories",
        "getRichardCategories",
        "getPresetImages",
        "includeRichard",
        "getSystemsNear",
        "x",
        "y",
        "z",
        "limit",
        "getSystemInformation",
        "getSystemInformationFromDB",
        "getSystemInformationFromCategory",
        "claimSystem",
        "commander",
        "unclaimSystem",
        "markSystemVisited",
        "updateSystemStatus",
        "visited",
        "done",
        "updateSystemVisited",
        "updateSystemDone",
        "markSystemAsEdited",
        "checkAdminStatus",
        "testAdminAccess",
        "serviceKey",
        "getSystemDetails",
        "getSystemDetailsRobust",
        "triggerWebhook",
        "QVariantMap",
        "data",
        "getWebhookConfig",
        "markSystemAsPOI",
        "poiType",
        "removePOIStatus",
        "updateSystemPOIStatus",
        "discoverer",
        "submitter",
        "saveSystemDescription",
        "description",
        "saveSystemInformation",
        "information",
        "updateSystemImages",
        "primaryImage",
        "primaryTitle",
        "additionalImages",
        "additionalTitles",
        "loadSystemImagesForSystems",
        "systemNames",
        "getTakenSystemForCommander",
        "getAllCommanderLocations",
        "updateCommanderLocation",
        "uploadImageToImgbb",
        "filePath",
        "testImgbbApiKey",
        "getPresetImageForCategory",
        "usePresetImageForSystem",
        "getSystemImageUrl",
        "saveImageToDatabase",
        "checkSystemVisitedInJournal",
        "initializeDatabaseSync",
        "checkForDatabaseUpdates",
        "performIncrementalSync",
        "calculateDistance",
        "x1",
        "y1",
        "z1",
        "x2",
        "y2",
        "z2",
        "isInAuthFailureCooldown"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'systemsReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 3 },
        }}),
        // Signal 'takenSystemsReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 5 },
        }}),
        // Signal 'poisReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 7 },
        }}),
        // Signal 'categoriesReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 9 },
        }}),
        // Signal 'presetImagesReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 11 },
        }}),
        // Signal 'nearestSystemsReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 3 },
        }}),
        // Signal 'systemInformationReceived'
        QtMocHelpers::SignalData<void(const QString &, const QJsonObject &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QJsonObject, 15 },
        }}),
        // Signal 'systemClaimed'
        QtMocHelpers::SignalData<void(const QString &, bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'systemUnclaimed'
        QtMocHelpers::SignalData<void(const QString &, bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'systemMarkedVisited'
        QtMocHelpers::SignalData<void(const QString &, bool)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'systemStatusUpdated'
        QtMocHelpers::SignalData<void(const QString &, bool)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'adminStatusReceived'
        QtMocHelpers::SignalData<void(bool)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 22 },
        }}),
        // Signal 'adminAccessTestComplete'
        QtMocHelpers::SignalData<void(bool)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 24 },
        }}),
        // Signal 'presetImageFound'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 26 }, { QMetaType::QString, 27 },
        }}),
        // Signal 'systemImageSet'
        QtMocHelpers::SignalData<void(const QString &, const QString &, bool)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 26 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'bulkSystemImagesLoaded'
        QtMocHelpers::SignalData<void(const QJsonObject &)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonObject, 30 },
        }}),
        // Signal 'allCommanderLocationsReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 32 },
        }}),
        // Signal 'commanderLocationUpdated'
        QtMocHelpers::SignalData<void(const QString &, bool)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 17 },
        }}),
        // Signal 'webhookConfigReceived'
        QtMocHelpers::SignalData<void(const QString &)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 36 },
        }}),
        // Signal 'webhookTriggered'
        QtMocHelpers::SignalData<void(bool, const QString &)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 }, { QMetaType::QString, 38 },
        }}),
        // Signal 'poiDataForMergeReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 40 },
        }}),
        // Signal 'networkError'
        QtMocHelpers::SignalData<void(const QString &)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 42 },
        }}),
        // Signal 'requestCompleted'
        QtMocHelpers::SignalData<void(const QString &, bool, const QString &)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 44 }, { QMetaType::Bool, 17 }, { QMetaType::QString, 45 },
        }}),
        // Signal 'databaseSyncStatusChanged'
        QtMocHelpers::SignalData<void(const QString &)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 47 },
        }}),
        // Signal 'databaseSyncProgress'
        QtMocHelpers::SignalData<void(int, int, const QString &)>(48, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 49 }, { QMetaType::Int, 50 }, { QMetaType::QString, 44 },
        }}),
        // Signal 'databaseSyncComplete'
        QtMocHelpers::SignalData<void(bool, int)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 52 }, { QMetaType::Int, 53 },
        }}),
        // Signal 'securityCheckComplete'
        QtMocHelpers::SignalData<void(const QString &, bool, const QString &)>(54, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 55 }, { QMetaType::QString, 56 },
        }}),
        // Signal 'securityCheckComplete'
        QtMocHelpers::SignalData<void(const QString &, bool)>(54, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 55 },
        }}),
        // Signal 'authenticationRequired'
        QtMocHelpers::SignalData<void()>(57, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'authenticationComplete'
        QtMocHelpers::SignalData<void(bool, const QString &)>(58, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 }, { QMetaType::QString, 45 },
        }}),
        // Signal 'authenticationComplete'
        QtMocHelpers::SignalData<void(bool)>(58, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Bool, 17 },
        }}),
        // Signal 'confirmationRequired'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 }, { QMetaType::QString, 45 }, { QMetaType::QString, 34 },
        }}),
        // Slot 'performSecurityCheck'
        QtMocHelpers::SlotData<void(const QString &)>(61, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 },
        }}),
        // Slot 'handleNewCommander'
        QtMocHelpers::SlotData<void(const QString &, const QStringList &)>(62, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::QStringList, 63 },
        }}),
        // Slot 'detectCommanderRenames'
        QtMocHelpers::SlotData<void(const QString &)>(64, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 65 },
        }}),
        // Slot 'logLoginEvent'
        QtMocHelpers::SlotData<void(const QString &, bool, const QString &, const QString &)>(66, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 22 }, { QMetaType::QString, 38 }, { QMetaType::QString, 67 },
        }}),
        // Slot 'logLoginEvent'
        QtMocHelpers::SlotData<void(const QString &, bool, const QString &)>(66, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 22 }, { QMetaType::QString, 38 },
        }}),
        // Slot 'isCommanderBlocked'
        QtMocHelpers::SlotData<bool(const QString &)>(68, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 34 },
        }}),
        // Slot 'addCommanderToSecurity'
        QtMocHelpers::SlotData<void(const QString &, bool, const QString &, const QString &)>(69, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 70 }, { QMetaType::QString, 71 }, { QMetaType::QString, 65 },
        }}),
        // Slot 'addCommanderToSecurity'
        QtMocHelpers::SlotData<void(const QString &, bool, const QString &)>(69, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 70 }, { QMetaType::QString, 71 },
        }}),
        // Slot 'addCommanderToSecurity'
        QtMocHelpers::SlotData<void(const QString &, bool)>(69, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Bool, 70 },
        }}),
        // Slot 'handleNetworkReply'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(72, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 73, 74 },
        }}),
        // Method 'configure'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(75, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 76 }, { QMetaType::QString, 77 },
        }}),
        // Method 'isConfigured'
        QtMocHelpers::MethodData<bool() const>(78, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'setCommanderContext'
        QtMocHelpers::MethodData<void(const QString &)>(79, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'getSystems'
        QtMocHelpers::MethodData<void()>(80, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getTakenSystems'
        QtMocHelpers::MethodData<void()>(81, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getCurrentCommanderSystems'
        QtMocHelpers::MethodData<void()>(82, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getPOISystems'
        QtMocHelpers::MethodData<void(const QString &)>(83, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'getPOISystems'
        QtMocHelpers::MethodData<void()>(83, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'getCategories'
        QtMocHelpers::MethodData<void()>(84, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getRichardCategories'
        QtMocHelpers::MethodData<void()>(85, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getPresetImages'
        QtMocHelpers::MethodData<void(bool)>(86, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 87 },
        }}),
        // Method 'getPresetImages'
        QtMocHelpers::MethodData<void()>(86, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'getSystemsNear'
        QtMocHelpers::MethodData<void(double, double, double, int)>(88, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 89 }, { QMetaType::Double, 90 }, { QMetaType::Double, 91 }, { QMetaType::Int, 92 },
        }}),
        // Method 'getSystemsNear'
        QtMocHelpers::MethodData<void(double, double, double)>(88, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Double, 89 }, { QMetaType::Double, 90 }, { QMetaType::Double, 91 },
        }}),
        // Method 'getSystemInformation'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(93, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 27 },
        }}),
        // Method 'getSystemInformation'
        QtMocHelpers::MethodData<void(const QString &)>(93, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'getSystemInformationFromDB'
        QtMocHelpers::MethodData<void(const QString &)>(94, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'getSystemInformationFromCategory'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(95, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 27 },
        }}),
        // Method 'claimSystem'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(96, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 97 },
        }}),
        // Method 'unclaimSystem'
        QtMocHelpers::MethodData<void(const QString &)>(98, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'markSystemVisited'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(99, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 97 },
        }}),
        // Method 'updateSystemStatus'
        QtMocHelpers::MethodData<void(const QString &, bool, bool)>(100, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 101 }, { QMetaType::Bool, 102 },
        }}),
        // Method 'updateSystemVisited'
        QtMocHelpers::MethodData<void(const QString &, bool)>(103, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 101 },
        }}),
        // Method 'updateSystemDone'
        QtMocHelpers::MethodData<void(const QString &, bool)>(104, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::Bool, 102 },
        }}),
        // Method 'markSystemAsEdited'
        QtMocHelpers::MethodData<void(const QString &)>(105, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'checkAdminStatus'
        QtMocHelpers::MethodData<void(const QString &)>(106, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 97 },
        }}),
        // Method 'testAdminAccess'
        QtMocHelpers::MethodData<void(const QString &)>(107, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 108 },
        }}),
        // Method 'getSystemDetails'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(109, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 27 },
        }}),
        // Method 'getSystemDetailsRobust'
        QtMocHelpers::MethodData<void(const QString &)>(110, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'triggerWebhook'
        QtMocHelpers::MethodData<void(const QString &, const QVariantMap &)>(111, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 38 }, { 0x80000000 | 112, 113 },
        }}),
        // Method 'getWebhookConfig'
        QtMocHelpers::MethodData<void()>(114, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'markSystemAsPOI'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &)>(115, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 116 }, { QMetaType::QString, 97 },
        }}),
        // Method 'removePOIStatus'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(117, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 97 },
        }}),
        // Method 'updateSystemPOIStatus'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &)>(118, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 116 }, { QMetaType::QString, 119 }, { QMetaType::QString, 120 },
        }}),
        // Method 'saveSystemDescription'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(121, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 122 },
        }}),
        // Method 'saveSystemInformation'
        QtMocHelpers::MethodData<void(const QString &, const QVariantMap &)>(123, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { 0x80000000 | 112, 124 },
        }}),
        // Method 'updateSystemImages'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &, const QString &)>(125, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 126 }, { QMetaType::QString, 127 }, { QMetaType::QString, 128 },
            { QMetaType::QString, 129 },
        }}),
        // Method 'loadSystemImagesForSystems'
        QtMocHelpers::MethodData<void(const QStringList &)>(130, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 131 },
        }}),
        // Method 'getTakenSystemForCommander'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(132, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 34 },
        }}),
        // Method 'getAllCommanderLocations'
        QtMocHelpers::MethodData<void()>(133, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'updateCommanderLocation'
        QtMocHelpers::MethodData<void(const QString &, double, double, double, const QString &)>(134, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 }, { QMetaType::Double, 89 }, { QMetaType::Double, 90 }, { QMetaType::Double, 91 },
            { QMetaType::QString, 14 },
        }}),
        // Method 'uploadImageToImgbb'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(135, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 136 }, { QMetaType::QString, 14 },
        }}),
        // Method 'testImgbbApiKey'
        QtMocHelpers::MethodData<void()>(137, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'getPresetImageForCategory'
        QtMocHelpers::MethodData<void(const QString &)>(138, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 27 },
        }}),
        // Method 'usePresetImageForSystem'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(139, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 27 },
        }}),
        // Method 'getSystemImageUrl'
        QtMocHelpers::MethodData<QString(const QString &, const QString &)>(140, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 27 },
        }}),
        // Method 'saveImageToDatabase'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(141, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 26 },
        }}),
        // Method 'checkSystemVisitedInJournal'
        QtMocHelpers::MethodData<bool(const QString &, const QString &)>(142, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 14 }, { QMetaType::QString, 34 },
        }}),
        // Method 'initializeDatabaseSync'
        QtMocHelpers::MethodData<void()>(143, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'checkForDatabaseUpdates'
        QtMocHelpers::MethodData<void()>(144, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'isFirstRun'
        QtMocHelpers::MethodData<bool() const>(52, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'performIncrementalSync'
        QtMocHelpers::MethodData<void()>(145, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'calculateDistance'
        QtMocHelpers::MethodData<double(double, double, double, double, double, double)>(146, 2, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::Double, 147 }, { QMetaType::Double, 148 }, { QMetaType::Double, 149 }, { QMetaType::Double, 150 },
            { QMetaType::Double, 151 }, { QMetaType::Double, 152 },
        }}),
        // Method 'isInAuthFailureCooldown'
        QtMocHelpers::MethodData<bool() const>(153, 2, QMC::AccessPublic, QMetaType::Bool),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SupabaseClient, qt_meta_tag_ZN14SupabaseClientE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SupabaseClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14SupabaseClientE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14SupabaseClientE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14SupabaseClientE_t>.metaTypes,
    nullptr
} };

void SupabaseClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SupabaseClient *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->systemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 1: _t->takenSystemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 2: _t->poisReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 3: _t->categoriesReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 4: _t->presetImagesReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 5: _t->nearestSystemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 6: _t->systemInformationReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 7: _t->systemClaimed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 8: _t->systemUnclaimed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 9: _t->systemMarkedVisited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 10: _t->systemStatusUpdated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 11: _t->adminStatusReceived((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->adminAccessTestComplete((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->presetImageFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 14: _t->systemImageSet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 15: _t->bulkSystemImagesLoaded((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 16: _t->allCommanderLocationsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 17: _t->commanderLocationUpdated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 18: _t->webhookConfigReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->webhookTriggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 20: _t->poiDataForMergeReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 21: _t->networkError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->requestCompleted((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 23: _t->databaseSyncStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->databaseSyncProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 25: _t->databaseSyncComplete((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 26: _t->securityCheckComplete((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 27: _t->securityCheckComplete((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 28: _t->authenticationRequired(); break;
        case 29: _t->authenticationComplete((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 30: _t->authenticationComplete((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 31: _t->confirmationRequired((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 32: _t->performSecurityCheck((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->handleNewCommander((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 34: _t->detectCommanderRenames((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->logLoginEvent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 36: _t->logLoginEvent((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 37: { bool _r = _t->isCommanderBlocked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->addCommanderToSecurity((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 39: _t->addCommanderToSecurity((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 40: _t->addCommanderToSecurity((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 41: _t->handleNetworkReply((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 42: _t->configure((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 43: { bool _r = _t->isConfigured();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 44: _t->setCommanderContext((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 45: _t->getSystems(); break;
        case 46: _t->getTakenSystems(); break;
        case 47: _t->getCurrentCommanderSystems(); break;
        case 48: _t->getPOISystems((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 49: _t->getPOISystems(); break;
        case 50: _t->getCategories(); break;
        case 51: _t->getRichardCategories(); break;
        case 52: _t->getPresetImages((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 53: _t->getPresetImages(); break;
        case 54: _t->getSystemsNear((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 55: _t->getSystemsNear((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 56: _t->getSystemInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 57: _t->getSystemInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 58: _t->getSystemInformationFromDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 59: _t->getSystemInformationFromCategory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 60: _t->claimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 61: _t->unclaimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 62: _t->markSystemVisited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 63: _t->updateSystemStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 64: _t->updateSystemVisited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 65: _t->updateSystemDone((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 66: _t->markSystemAsEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 67: _t->checkAdminStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 68: _t->testAdminAccess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 69: _t->getSystemDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 70: _t->getSystemDetailsRobust((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 71: _t->triggerWebhook((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 72: _t->getWebhookConfig(); break;
        case 73: _t->markSystemAsPOI((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 74: _t->removePOIStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 75: _t->updateSystemPOIStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 76: _t->saveSystemDescription((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 77: _t->saveSystemInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 78: _t->updateSystemImages((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 79: _t->loadSystemImagesForSystems((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 80: _t->getTakenSystemForCommander((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 81: _t->getAllCommanderLocations(); break;
        case 82: _t->updateCommanderLocation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 83: _t->uploadImageToImgbb((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 84: _t->testImgbbApiKey(); break;
        case 85: _t->getPresetImageForCategory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 86: _t->usePresetImageForSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 87: { QString _r = _t->getSystemImageUrl((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 88: _t->saveImageToDatabase((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 89: { bool _r = _t->checkSystemVisitedInJournal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 90: _t->initializeDatabaseSync(); break;
        case 91: _t->checkForDatabaseUpdates(); break;
        case 92: { bool _r = _t->isFirstRun();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 93: _t->performIncrementalSync(); break;
        case 94: { double _r = _t->calculateDistance((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[6])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 95: { bool _r = _t->isInAuthFailureCooldown();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::systemsReceived, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::takenSystemsReceived, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::poisReceived, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::categoriesReceived, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::presetImagesReceived, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::nearestSystemsReceived, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , const QJsonObject & )>(_a, &SupabaseClient::systemInformationReceived, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool )>(_a, &SupabaseClient::systemClaimed, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool )>(_a, &SupabaseClient::systemUnclaimed, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool )>(_a, &SupabaseClient::systemMarkedVisited, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool )>(_a, &SupabaseClient::systemStatusUpdated, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(bool )>(_a, &SupabaseClient::adminStatusReceived, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(bool )>(_a, &SupabaseClient::adminAccessTestComplete, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , const QString & , const QString & )>(_a, &SupabaseClient::presetImageFound, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , const QString & , bool )>(_a, &SupabaseClient::systemImageSet, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonObject & )>(_a, &SupabaseClient::bulkSystemImagesLoaded, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::allCommanderLocationsReceived, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool )>(_a, &SupabaseClient::commanderLocationUpdated, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & )>(_a, &SupabaseClient::webhookConfigReceived, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(bool , const QString & )>(_a, &SupabaseClient::webhookTriggered, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QJsonArray & )>(_a, &SupabaseClient::poiDataForMergeReceived, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & )>(_a, &SupabaseClient::networkError, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool , const QString & )>(_a, &SupabaseClient::requestCompleted, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & )>(_a, &SupabaseClient::databaseSyncStatusChanged, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(int , int , const QString & )>(_a, &SupabaseClient::databaseSyncProgress, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(bool , int )>(_a, &SupabaseClient::databaseSyncComplete, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , bool , const QString & )>(_a, &SupabaseClient::securityCheckComplete, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)()>(_a, &SupabaseClient::authenticationRequired, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(bool , const QString & )>(_a, &SupabaseClient::authenticationComplete, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (SupabaseClient::*)(const QString & , const QString & , const QString & )>(_a, &SupabaseClient::confirmationRequired, 31))
            return;
    }
}

const QMetaObject *SupabaseClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SupabaseClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14SupabaseClientE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SupabaseClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 96)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 96;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 96)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 96;
    }
    return _id;
}

// SIGNAL 0
void SupabaseClient::systemsReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SupabaseClient::takenSystemsReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void SupabaseClient::poisReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void SupabaseClient::categoriesReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void SupabaseClient::presetImagesReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void SupabaseClient::nearestSystemsReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void SupabaseClient::systemInformationReceived(const QString & _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void SupabaseClient::systemClaimed(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 8
void SupabaseClient::systemUnclaimed(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void SupabaseClient::systemMarkedVisited(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void SupabaseClient::systemStatusUpdated(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2);
}

// SIGNAL 11
void SupabaseClient::adminStatusReceived(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void SupabaseClient::adminAccessTestComplete(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void SupabaseClient::presetImageFound(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2, _t3);
}

// SIGNAL 14
void SupabaseClient::systemImageSet(const QString & _t1, const QString & _t2, bool _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1, _t2, _t3);
}

// SIGNAL 15
void SupabaseClient::bulkSystemImagesLoaded(const QJsonObject & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void SupabaseClient::allCommanderLocationsReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void SupabaseClient::commanderLocationUpdated(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1, _t2);
}

// SIGNAL 18
void SupabaseClient::webhookConfigReceived(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void SupabaseClient::webhookTriggered(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1, _t2);
}

// SIGNAL 20
void SupabaseClient::poiDataForMergeReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1);
}

// SIGNAL 21
void SupabaseClient::networkError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1);
}

// SIGNAL 22
void SupabaseClient::requestCompleted(const QString & _t1, bool _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1, _t2, _t3);
}

// SIGNAL 23
void SupabaseClient::databaseSyncStatusChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}

// SIGNAL 24
void SupabaseClient::databaseSyncProgress(int _t1, int _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 24, nullptr, _t1, _t2, _t3);
}

// SIGNAL 25
void SupabaseClient::databaseSyncComplete(bool _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 25, nullptr, _t1, _t2);
}

// SIGNAL 26
void SupabaseClient::securityCheckComplete(const QString & _t1, bool _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 26, nullptr, _t1, _t2, _t3);
}

// SIGNAL 28
void SupabaseClient::authenticationRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void SupabaseClient::authenticationComplete(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 29, nullptr, _t1, _t2);
}

// SIGNAL 31
void SupabaseClient::confirmationRequired(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 31, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
