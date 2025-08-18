/****************************************************************************
** Meta object code from reading C++ file 'edrhcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../edrhcontroller.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edrhcontroller.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14EDRHControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto EDRHController::qt_create_metaobjectdata<qt_meta_tag_ZN14EDRHControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EDRHController",
        "QML.Element",
        "auto",
        "commanderNameChanged",
        "",
        "currentSystemChanged",
        "isAdminChanged",
        "nearestSystemsChanged",
        "unclaimedSystemsChanged",
        "selectedCategoryChanged",
        "availableCategoriesChanged",
        "jumpCountChanged",
        "sessionTimeChanged",
        "mapWindowActiveChanged",
        "nearestDistanceTextChanged",
        "nearestCategoryTextChanged",
        "unclaimedIndexChanged",
        "unclaimedTotalChanged",
        "currentUnclaimedSystemNameChanged",
        "suppressMainAppNotificationsChanged",
        "galaxyMapSystemsChanged",
        "commanderPositionChanged",
        "visibleSystemsCountChanged",
        "galaxyMapLoadingChanged",
        "allCommanderLocationsChanged",
        "showMessage",
        "title",
        "message",
        "showError",
        "navigationRequested",
        "systemName",
        "systemUpdated",
        "showSystemPopup",
        "QVariantMap",
        "systemData",
        "openGalaxyMapWindow",
        "systemInformationReceived",
        "systemInfo",
        "requestFilterChange",
        "systemTypeFilter",
        "edsmSystemDataReceived",
        "systemClaimed",
        "success",
        "systemUnclaimed",
        "systemImageSet",
        "imageUrl",
        "systemImagesUpdated",
        "systemNames",
        "databaseDownloadProgress",
        "progress",
        "status",
        "databaseDownloadComplete",
        "requestImagePicker",
        "refreshData",
        "viewCurrentSystem",
        "createPOI",
        "openMap",
        "openGalaxyMap",
        "claimSystem",
        "viewSystem",
        "viewYourSystems",
        "copyToClipboard",
        "text",
        "showAdminPanel",
        "prevUnclaimed",
        "nextUnclaimed",
        "viewClosest",
        "claimClosest",
        "markSystemVisited",
        "markSystemDone",
        "unclaimSystem",
        "getSystemInformation",
        "category",
        "getSystemInformationRobust",
        "isSystemClaimable",
        "getSystemFromEDSM",
        "getEDSMSystemData",
        "markSystemAsPOI",
        "poiType",
        "removePOIStatus",
        "verifyJournal",
        "revokeJournalVerification",
        "saveSystemDescription",
        "description",
        "openImagePicker",
        "handleImageSelected",
        "fileName",
        "uploadImageToImgbb",
        "filePath",
        "checkSystemVisitedInJournal",
        "saveSystemInformation",
        "information",
        "updateSystemStatus",
        "visited",
        "done",
        "updateSystemVisited",
        "updateSystemDone",
        "markSystemAsEdited",
        "updateSystemImages",
        "primaryImage",
        "primaryTitle",
        "additionalImages",
        "additionalTitles",
        "getPrimaryImageForSystem",
        "loadGalaxyMapData",
        "updateGalaxyMapFilters",
        "filters",
        "focusOnSystem",
        "getSystemsInRegion",
        "minX",
        "maxX",
        "minZ",
        "maxZ",
        "updateCategoryFilter",
        "categories",
        "resetCategoryFilter",
        "startJournalMonitoring",
        "stopJournalMonitoring",
        "selectJournalFolder",
        "startFullDatabaseDownload",
        "updateSessionTime",
        "processJournalUpdate",
        "handleSystemsReceived",
        "systems",
        "handleNearestSystemsReceived",
        "handleTakenSystemsReceived",
        "taken",
        "handleCategoriesReceived",
        "handlePOISReceived",
        "pois",
        "handlePOIDataForMerge",
        "poiData",
        "handleSystemInformationReceived",
        "handleAllCommanderLocationsReceived",
        "locations",
        "handleBulkSystemImagesLoaded",
        "systemImages",
        "handleSupabaseError",
        "error",
        "commanderName",
        "currentSystem",
        "appVersion",
        "isAdmin",
        "nearestSystems",
        "QVariantList",
        "unclaimedSystems",
        "selectedCategory",
        "availableCategories",
        "jumpCount",
        "sessionTime",
        "mapWindowActive",
        "nearestDistanceText",
        "nearestCategoryText",
        "unclaimedIndex",
        "unclaimedTotal",
        "currentUnclaimedSystemName",
        "suppressMainAppNotifications",
        "supabaseClient",
        "SupabaseClient*",
        "claimManager",
        "ClaimManager*",
        "galaxyMapSystems",
        "commanderPosition",
        "visibleSystemsCount",
        "galaxyMapLoading",
        "allCommanderLocations",
        "commanderX",
        "commanderZ"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'commanderNameChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentSystemChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isAdminChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nearestSystemsChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'unclaimedSystemsChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'selectedCategoryChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'availableCategoriesChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'jumpCountChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sessionTimeChanged'
        QtMocHelpers::SignalData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'mapWindowActiveChanged'
        QtMocHelpers::SignalData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nearestDistanceTextChanged'
        QtMocHelpers::SignalData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nearestCategoryTextChanged'
        QtMocHelpers::SignalData<void()>(15, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'unclaimedIndexChanged'
        QtMocHelpers::SignalData<void()>(16, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'unclaimedTotalChanged'
        QtMocHelpers::SignalData<void()>(17, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentUnclaimedSystemNameChanged'
        QtMocHelpers::SignalData<void()>(18, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'suppressMainAppNotificationsChanged'
        QtMocHelpers::SignalData<void()>(19, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'galaxyMapSystemsChanged'
        QtMocHelpers::SignalData<void()>(20, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commanderPositionChanged'
        QtMocHelpers::SignalData<void()>(21, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'visibleSystemsCountChanged'
        QtMocHelpers::SignalData<void()>(22, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'galaxyMapLoadingChanged'
        QtMocHelpers::SignalData<void()>(23, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'allCommanderLocationsChanged'
        QtMocHelpers::SignalData<void()>(24, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showMessage'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(25, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 27 },
        }}),
        // Signal 'showError'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(28, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 26 }, { QMetaType::QString, 27 },
        }}),
        // Signal 'navigationRequested'
        QtMocHelpers::SignalData<void(const QString &)>(29, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Signal 'systemUpdated'
        QtMocHelpers::SignalData<void()>(31, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showSystemPopup'
        QtMocHelpers::SignalData<void(const QString &, const QVariantMap &)>(32, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { 0x80000000 | 33, 34 },
        }}),
        // Signal 'openGalaxyMapWindow'
        QtMocHelpers::SignalData<void()>(35, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'systemInformationReceived'
        QtMocHelpers::SignalData<void(const QString &, const QVariantMap &)>(36, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { 0x80000000 | 33, 37 },
        }}),
        // Signal 'requestFilterChange'
        QtMocHelpers::SignalData<void(const QString &)>(38, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 39 },
        }}),
        // Signal 'edsmSystemDataReceived'
        QtMocHelpers::SignalData<void(const QString &, const QVariantMap &)>(40, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { 0x80000000 | 33, 34 },
        }}),
        // Signal 'systemClaimed'
        QtMocHelpers::SignalData<void(const QString &, bool)>(41, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::Bool, 42 },
        }}),
        // Signal 'systemUnclaimed'
        QtMocHelpers::SignalData<void(const QString &, bool)>(43, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::Bool, 42 },
        }}),
        // Signal 'systemImageSet'
        QtMocHelpers::SignalData<void(const QString &, const QString &, bool)>(44, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QString, 45 }, { QMetaType::Bool, 42 },
        }}),
        // Signal 'systemImagesUpdated'
        QtMocHelpers::SignalData<void(const QStringList &)>(46, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 47 },
        }}),
        // Signal 'databaseDownloadProgress'
        QtMocHelpers::SignalData<void(double, const QString &)>(48, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 49 }, { QMetaType::QString, 50 },
        }}),
        // Signal 'databaseDownloadComplete'
        QtMocHelpers::SignalData<void()>(51, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'requestImagePicker'
        QtMocHelpers::SignalData<void(const QString &)>(52, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'refreshData'
        QtMocHelpers::SlotData<void()>(53, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'viewCurrentSystem'
        QtMocHelpers::SlotData<void()>(54, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'createPOI'
        QtMocHelpers::SlotData<void()>(55, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'openMap'
        QtMocHelpers::SlotData<void()>(56, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'openGalaxyMap'
        QtMocHelpers::SlotData<void()>(57, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'claimSystem'
        QtMocHelpers::SlotData<void(const QString &)>(58, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'viewSystem'
        QtMocHelpers::SlotData<void(const QString &)>(59, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'viewYourSystems'
        QtMocHelpers::SlotData<void()>(60, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'copyToClipboard'
        QtMocHelpers::SlotData<void(const QString &)>(61, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 62 },
        }}),
        // Slot 'showAdminPanel'
        QtMocHelpers::SlotData<void()>(63, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'prevUnclaimed'
        QtMocHelpers::SlotData<void()>(64, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'nextUnclaimed'
        QtMocHelpers::SlotData<void()>(65, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'viewClosest'
        QtMocHelpers::SlotData<void()>(66, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'claimClosest'
        QtMocHelpers::SlotData<void()>(67, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'markSystemVisited'
        QtMocHelpers::SlotData<void(const QString &)>(68, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'markSystemDone'
        QtMocHelpers::SlotData<void(const QString &)>(69, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'unclaimSystem'
        QtMocHelpers::SlotData<void(const QString &)>(70, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'getSystemInformation'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(71, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QString, 72 },
        }}),
        // Slot 'getSystemInformation'
        QtMocHelpers::SlotData<void(const QString &)>(71, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'getSystemInformationRobust'
        QtMocHelpers::SlotData<void(const QString &)>(73, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'isSystemClaimable'
        QtMocHelpers::SlotData<bool(const QString &) const>(74, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'getSystemFromEDSM'
        QtMocHelpers::SlotData<void(const QString &)>(75, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'getEDSMSystemData'
        QtMocHelpers::SlotData<void(const QString &)>(76, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'markSystemAsPOI'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(77, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QString, 78 },
        }}),
        // Slot 'removePOIStatus'
        QtMocHelpers::SlotData<void(const QString &)>(79, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'verifyJournal'
        QtMocHelpers::SlotData<void()>(80, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'revokeJournalVerification'
        QtMocHelpers::SlotData<void()>(81, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'saveSystemDescription'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(82, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QString, 83 },
        }}),
        // Slot 'openImagePicker'
        QtMocHelpers::SlotData<void(const QString &)>(84, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'handleImageSelected'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(85, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QString, 86 },
        }}),
        // Slot 'uploadImageToImgbb'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(87, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 88 }, { QMetaType::QString, 30 },
        }}),
        // Slot 'checkSystemVisitedInJournal'
        QtMocHelpers::SlotData<bool(const QString &) const>(89, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'saveSystemInformation'
        QtMocHelpers::SlotData<void(const QString &, const QVariantMap &)>(90, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { 0x80000000 | 33, 91 },
        }}),
        // Slot 'updateSystemStatus'
        QtMocHelpers::SlotData<void(const QString &, bool, bool)>(92, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::Bool, 93 }, { QMetaType::Bool, 94 },
        }}),
        // Slot 'updateSystemVisited'
        QtMocHelpers::SlotData<void(const QString &, bool)>(95, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::Bool, 93 },
        }}),
        // Slot 'updateSystemDone'
        QtMocHelpers::SlotData<void(const QString &, bool)>(96, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::Bool, 94 },
        }}),
        // Slot 'markSystemAsEdited'
        QtMocHelpers::SlotData<void(const QString &)>(97, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'updateSystemImages'
        QtMocHelpers::SlotData<void(const QString &, const QString &, const QString &, const QString &, const QString &)>(98, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QString, 99 }, { QMetaType::QString, 100 }, { QMetaType::QString, 101 },
            { QMetaType::QString, 102 },
        }}),
        // Slot 'getPrimaryImageForSystem'
        QtMocHelpers::SlotData<QString(const QString &) const>(103, 4, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'loadGalaxyMapData'
        QtMocHelpers::SlotData<void()>(104, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateGalaxyMapFilters'
        QtMocHelpers::SlotData<void(const QVariantMap &)>(105, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 33, 106 },
        }}),
        // Slot 'focusOnSystem'
        QtMocHelpers::SlotData<void(const QString &)>(107, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 30 },
        }}),
        // Slot 'getSystemsInRegion'
        QtMocHelpers::SlotData<QVariantMap(double, double, double, double)>(108, 4, QMC::AccessPublic, 0x80000000 | 33, {{
            { QMetaType::Double, 109 }, { QMetaType::Double, 110 }, { QMetaType::Double, 111 }, { QMetaType::Double, 112 },
        }}),
        // Slot 'updateCategoryFilter'
        QtMocHelpers::SlotData<void(const QStringList &)>(113, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 114 },
        }}),
        // Slot 'resetCategoryFilter'
        QtMocHelpers::SlotData<void()>(115, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startJournalMonitoring'
        QtMocHelpers::SlotData<void()>(116, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopJournalMonitoring'
        QtMocHelpers::SlotData<void()>(117, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectJournalFolder'
        QtMocHelpers::SlotData<void()>(118, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startFullDatabaseDownload'
        QtMocHelpers::SlotData<void()>(119, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateSessionTime'
        QtMocHelpers::SlotData<void()>(120, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'processJournalUpdate'
        QtMocHelpers::SlotData<void()>(121, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleSystemsReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(122, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 123 },
        }}),
        // Slot 'handleNearestSystemsReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(124, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 123 },
        }}),
        // Slot 'handleTakenSystemsReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(125, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 126 },
        }}),
        // Slot 'handleCategoriesReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(127, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 114 },
        }}),
        // Slot 'handlePOISReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(128, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 129 },
        }}),
        // Slot 'handlePOIDataForMerge'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(130, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 131 },
        }}),
        // Slot 'handleSystemInformationReceived'
        QtMocHelpers::SlotData<void(const QString &, const QJsonObject &)>(132, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 30 }, { QMetaType::QJsonObject, 37 },
        }}),
        // Slot 'handleAllCommanderLocationsReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(133, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonArray, 134 },
        }}),
        // Slot 'handleBulkSystemImagesLoaded'
        QtMocHelpers::SlotData<void(const QJsonObject &)>(135, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QJsonObject, 136 },
        }}),
        // Slot 'handleSupabaseError'
        QtMocHelpers::SlotData<void(const QString &)>(137, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 138 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'commanderName'
        QtMocHelpers::PropertyData<QString>(139, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'currentSystem'
        QtMocHelpers::PropertyData<QString>(140, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'appVersion'
        QtMocHelpers::PropertyData<QString>(141, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'isAdmin'
        QtMocHelpers::PropertyData<bool>(142, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'nearestSystems'
        QtMocHelpers::PropertyData<QVariantList>(143, 0x80000000 | 144, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'unclaimedSystems'
        QtMocHelpers::PropertyData<QVariantList>(145, 0x80000000 | 144, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 4),
        // property 'selectedCategory'
        QtMocHelpers::PropertyData<QString>(146, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'availableCategories'
        QtMocHelpers::PropertyData<QVariantList>(147, 0x80000000 | 144, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 6),
        // property 'jumpCount'
        QtMocHelpers::PropertyData<int>(148, QMetaType::Int, QMC::DefaultPropertyFlags, 7),
        // property 'sessionTime'
        QtMocHelpers::PropertyData<QString>(149, QMetaType::QString, QMC::DefaultPropertyFlags, 8),
        // property 'mapWindowActive'
        QtMocHelpers::PropertyData<bool>(150, QMetaType::Bool, QMC::DefaultPropertyFlags, 9),
        // property 'nearestDistanceText'
        QtMocHelpers::PropertyData<QString>(151, QMetaType::QString, QMC::DefaultPropertyFlags, 10),
        // property 'nearestCategoryText'
        QtMocHelpers::PropertyData<QString>(152, QMetaType::QString, QMC::DefaultPropertyFlags, 11),
        // property 'unclaimedIndex'
        QtMocHelpers::PropertyData<int>(153, QMetaType::Int, QMC::DefaultPropertyFlags, 12),
        // property 'unclaimedTotal'
        QtMocHelpers::PropertyData<int>(154, QMetaType::Int, QMC::DefaultPropertyFlags, 13),
        // property 'currentUnclaimedSystemName'
        QtMocHelpers::PropertyData<QString>(155, QMetaType::QString, QMC::DefaultPropertyFlags, 14),
        // property 'suppressMainAppNotifications'
        QtMocHelpers::PropertyData<bool>(156, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'supabaseClient'
        QtMocHelpers::PropertyData<SupabaseClient*>(157, 0x80000000 | 158, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'claimManager'
        QtMocHelpers::PropertyData<ClaimManager*>(159, 0x80000000 | 160, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'galaxyMapSystems'
        QtMocHelpers::PropertyData<QVariantList>(161, 0x80000000 | 144, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 16),
        // property 'commanderPosition'
        QtMocHelpers::PropertyData<QVariantMap>(162, 0x80000000 | 33, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 17),
        // property 'visibleSystemsCount'
        QtMocHelpers::PropertyData<int>(163, QMetaType::Int, QMC::DefaultPropertyFlags, 18),
        // property 'galaxyMapLoading'
        QtMocHelpers::PropertyData<bool>(164, QMetaType::Bool, QMC::DefaultPropertyFlags, 19),
        // property 'allCommanderLocations'
        QtMocHelpers::PropertyData<QVariantList>(165, 0x80000000 | 144, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 20),
        // property 'commanderX'
        QtMocHelpers::PropertyData<double>(166, QMetaType::Double, QMC::DefaultPropertyFlags, 17),
        // property 'commanderZ'
        QtMocHelpers::PropertyData<double>(167, QMetaType::Double, QMC::DefaultPropertyFlags, 17),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<EDRHController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject EDRHController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14EDRHControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14EDRHControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14EDRHControllerE_t>.metaTypes,
    nullptr
} };

void EDRHController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EDRHController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->commanderNameChanged(); break;
        case 1: _t->currentSystemChanged(); break;
        case 2: _t->isAdminChanged(); break;
        case 3: _t->nearestSystemsChanged(); break;
        case 4: _t->unclaimedSystemsChanged(); break;
        case 5: _t->selectedCategoryChanged(); break;
        case 6: _t->availableCategoriesChanged(); break;
        case 7: _t->jumpCountChanged(); break;
        case 8: _t->sessionTimeChanged(); break;
        case 9: _t->mapWindowActiveChanged(); break;
        case 10: _t->nearestDistanceTextChanged(); break;
        case 11: _t->nearestCategoryTextChanged(); break;
        case 12: _t->unclaimedIndexChanged(); break;
        case 13: _t->unclaimedTotalChanged(); break;
        case 14: _t->currentUnclaimedSystemNameChanged(); break;
        case 15: _t->suppressMainAppNotificationsChanged(); break;
        case 16: _t->galaxyMapSystemsChanged(); break;
        case 17: _t->commanderPositionChanged(); break;
        case 18: _t->visibleSystemsCountChanged(); break;
        case 19: _t->galaxyMapLoadingChanged(); break;
        case 20: _t->allCommanderLocationsChanged(); break;
        case 21: _t->showMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 22: _t->showError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 23: _t->navigationRequested((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->systemUpdated(); break;
        case 25: _t->showSystemPopup((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 26: _t->openGalaxyMapWindow(); break;
        case 27: _t->systemInformationReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 28: _t->requestFilterChange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->edsmSystemDataReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 30: _t->systemClaimed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 31: _t->systemUnclaimed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 32: _t->systemImageSet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 33: _t->systemImagesUpdated((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 34: _t->databaseDownloadProgress((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 35: _t->databaseDownloadComplete(); break;
        case 36: _t->requestImagePicker((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 37: _t->refreshData(); break;
        case 38: _t->viewCurrentSystem(); break;
        case 39: _t->createPOI(); break;
        case 40: _t->openMap(); break;
        case 41: _t->openGalaxyMap(); break;
        case 42: _t->claimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 43: _t->viewSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: _t->viewYourSystems(); break;
        case 45: _t->copyToClipboard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 46: _t->showAdminPanel(); break;
        case 47: _t->prevUnclaimed(); break;
        case 48: _t->nextUnclaimed(); break;
        case 49: _t->viewClosest(); break;
        case 50: _t->claimClosest(); break;
        case 51: _t->markSystemVisited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 52: _t->markSystemDone((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 53: _t->unclaimSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 54: _t->getSystemInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 55: _t->getSystemInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 56: _t->getSystemInformationRobust((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 57: { bool _r = _t->isSystemClaimable((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 58: _t->getSystemFromEDSM((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 59: _t->getEDSMSystemData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 60: _t->markSystemAsPOI((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 61: _t->removePOIStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 62: _t->verifyJournal(); break;
        case 63: _t->revokeJournalVerification(); break;
        case 64: _t->saveSystemDescription((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 65: _t->openImagePicker((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 66: _t->handleImageSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 67: _t->uploadImageToImgbb((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 68: { bool _r = _t->checkSystemVisitedInJournal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 69: _t->saveSystemInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 70: _t->updateSystemStatus((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 71: _t->updateSystemVisited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 72: _t->updateSystemDone((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 73: _t->markSystemAsEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 74: _t->updateSystemImages((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 75: { QString _r = _t->getPrimaryImageForSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 76: _t->loadGalaxyMapData(); break;
        case 77: _t->updateGalaxyMapFilters((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 78: _t->focusOnSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 79: { QVariantMap _r = _t->getSystemsInRegion((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 80: _t->updateCategoryFilter((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 81: _t->resetCategoryFilter(); break;
        case 82: _t->startJournalMonitoring(); break;
        case 83: _t->stopJournalMonitoring(); break;
        case 84: _t->selectJournalFolder(); break;
        case 85: _t->startFullDatabaseDownload(); break;
        case 86: _t->updateSessionTime(); break;
        case 87: _t->processJournalUpdate(); break;
        case 88: _t->handleSystemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 89: _t->handleNearestSystemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 90: _t->handleTakenSystemsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 91: _t->handleCategoriesReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 92: _t->handlePOISReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 93: _t->handlePOIDataForMerge((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 94: _t->handleSystemInformationReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 95: _t->handleAllCommanderLocationsReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 96: _t->handleBulkSystemImagesLoaded((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 97: _t->handleSupabaseError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::commanderNameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::currentSystemChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::isAdminChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::nearestSystemsChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::unclaimedSystemsChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::selectedCategoryChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::availableCategoriesChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::jumpCountChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::sessionTimeChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::mapWindowActiveChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::nearestDistanceTextChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::nearestCategoryTextChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::unclaimedIndexChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::unclaimedTotalChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::currentUnclaimedSystemNameChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::suppressMainAppNotificationsChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::galaxyMapSystemsChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::commanderPositionChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::visibleSystemsCountChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::galaxyMapLoadingChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::allCommanderLocationsChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , const QString & )>(_a, &EDRHController::showMessage, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , const QString & )>(_a, &EDRHController::showError, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & )>(_a, &EDRHController::navigationRequested, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::systemUpdated, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , const QVariantMap & )>(_a, &EDRHController::showSystemPopup, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::openGalaxyMapWindow, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , const QVariantMap & )>(_a, &EDRHController::systemInformationReceived, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & )>(_a, &EDRHController::requestFilterChange, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , const QVariantMap & )>(_a, &EDRHController::edsmSystemDataReceived, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , bool )>(_a, &EDRHController::systemClaimed, 30))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , bool )>(_a, &EDRHController::systemUnclaimed, 31))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & , const QString & , bool )>(_a, &EDRHController::systemImageSet, 32))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QStringList & )>(_a, &EDRHController::systemImagesUpdated, 33))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(double , const QString & )>(_a, &EDRHController::databaseDownloadProgress, 34))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)()>(_a, &EDRHController::databaseDownloadComplete, 35))
            return;
        if (QtMocHelpers::indexOfMethod<void (EDRHController::*)(const QString & )>(_a, &EDRHController::requestImagePicker, 36))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 17:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SupabaseClient* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->commanderName(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->currentSystem(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->appVersion(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isAdmin(); break;
        case 4: *reinterpret_cast<QVariantList*>(_v) = _t->nearestSystems(); break;
        case 5: *reinterpret_cast<QVariantList*>(_v) = _t->unclaimedSystems(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->selectedCategory(); break;
        case 7: *reinterpret_cast<QVariantList*>(_v) = _t->availableCategories(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->jumpCount(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->sessionTime(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->mapWindowActive(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->nearestDistanceText(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->nearestCategoryText(); break;
        case 13: *reinterpret_cast<int*>(_v) = _t->unclaimedIndex(); break;
        case 14: *reinterpret_cast<int*>(_v) = _t->unclaimedTotal(); break;
        case 15: *reinterpret_cast<QString*>(_v) = _t->currentUnclaimedSystemName(); break;
        case 16: *reinterpret_cast<bool*>(_v) = _t->suppressMainAppNotifications(); break;
        case 17: *reinterpret_cast<SupabaseClient**>(_v) = _t->supabaseClient(); break;
        case 18: *reinterpret_cast<ClaimManager**>(_v) = _t->claimManager(); break;
        case 19: *reinterpret_cast<QVariantList*>(_v) = _t->galaxyMapSystems(); break;
        case 20: *reinterpret_cast<QVariantMap*>(_v) = _t->commanderPosition(); break;
        case 21: *reinterpret_cast<int*>(_v) = _t->visibleSystemsCount(); break;
        case 22: *reinterpret_cast<bool*>(_v) = _t->galaxyMapLoading(); break;
        case 23: *reinterpret_cast<QVariantList*>(_v) = _t->allCommanderLocations(); break;
        case 24: *reinterpret_cast<double*>(_v) = _t->commanderX(); break;
        case 25: *reinterpret_cast<double*>(_v) = _t->commanderZ(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCommanderName(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setCurrentSystem(*reinterpret_cast<QString*>(_v)); break;
        case 6: _t->setSelectedCategory(*reinterpret_cast<QString*>(_v)); break;
        case 16: _t->setSuppressMainAppNotifications(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *EDRHController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EDRHController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14EDRHControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EDRHController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 98)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 98;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 98)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 98;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void EDRHController::commanderNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EDRHController::currentSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EDRHController::isAdminChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void EDRHController::nearestSystemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EDRHController::unclaimedSystemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void EDRHController::selectedCategoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void EDRHController::availableCategoriesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void EDRHController::jumpCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void EDRHController::sessionTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void EDRHController::mapWindowActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void EDRHController::nearestDistanceTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void EDRHController::nearestCategoryTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void EDRHController::unclaimedIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void EDRHController::unclaimedTotalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void EDRHController::currentUnclaimedSystemNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void EDRHController::suppressMainAppNotificationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void EDRHController::galaxyMapSystemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void EDRHController::commanderPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void EDRHController::visibleSystemsCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void EDRHController::galaxyMapLoadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void EDRHController::allCommanderLocationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void EDRHController::showMessage(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1, _t2);
}

// SIGNAL 22
void EDRHController::showError(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1, _t2);
}

// SIGNAL 23
void EDRHController::navigationRequested(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 23, nullptr, _t1);
}

// SIGNAL 24
void EDRHController::systemUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void EDRHController::showSystemPopup(const QString & _t1, const QVariantMap & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 25, nullptr, _t1, _t2);
}

// SIGNAL 26
void EDRHController::openGalaxyMapWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void EDRHController::systemInformationReceived(const QString & _t1, const QVariantMap & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 27, nullptr, _t1, _t2);
}

// SIGNAL 28
void EDRHController::requestFilterChange(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 28, nullptr, _t1);
}

// SIGNAL 29
void EDRHController::edsmSystemDataReceived(const QString & _t1, const QVariantMap & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 29, nullptr, _t1, _t2);
}

// SIGNAL 30
void EDRHController::systemClaimed(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 30, nullptr, _t1, _t2);
}

// SIGNAL 31
void EDRHController::systemUnclaimed(const QString & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 31, nullptr, _t1, _t2);
}

// SIGNAL 32
void EDRHController::systemImageSet(const QString & _t1, const QString & _t2, bool _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 32, nullptr, _t1, _t2, _t3);
}

// SIGNAL 33
void EDRHController::systemImagesUpdated(const QStringList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 33, nullptr, _t1);
}

// SIGNAL 34
void EDRHController::databaseDownloadProgress(double _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 34, nullptr, _t1, _t2);
}

// SIGNAL 35
void EDRHController::databaseDownloadComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 35, nullptr);
}

// SIGNAL 36
void EDRHController::requestImagePicker(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 36, nullptr, _t1);
}
QT_WARNING_POP
