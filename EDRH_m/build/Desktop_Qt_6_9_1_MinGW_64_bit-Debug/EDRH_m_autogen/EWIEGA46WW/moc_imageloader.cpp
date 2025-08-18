/****************************************************************************
** Meta object code from reading C++ file 'imageloader.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../imageloader.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageloader.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11ImageLoaderE_t {};
} // unnamed namespace

template <> constexpr inline auto ImageLoader::qt_create_metaobjectdata<qt_meta_tag_ZN11ImageLoaderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ImageLoader",
        "QML.Element",
        "auto",
        "imageLoaded",
        "",
        "url",
        "imagePath",
        "imageLoadFailed",
        "error",
        "presetImageLoaded",
        "category",
        "presetImagesFromDatabaseLoaded",
        "presetImages",
        "presetImagesReady",
        "cacheCleared",
        "handlePresetImagesReceived",
        "handleImageDownloaded",
        "handleNetworkError",
        "QNetworkReply::NetworkError",
        "loadImage",
        "systemName",
        "loadPresetImage",
        "loadPresetImagesFromDatabase",
        "includeRichard",
        "getCachedImagePath",
        "getCachedImageFileUrl",
        "hasPresetImage",
        "getPresetImageUrl",
        "getPresetImageFileUrl",
        "clearCache",
        "preloadCommonImages"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'imageLoaded'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(3, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'imageLoadFailed'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(7, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 8 },
        }}),
        // Signal 'presetImageLoaded'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(9, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'presetImagesFromDatabaseLoaded'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(11, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 12 },
        }}),
        // Signal 'presetImagesReady'
        QtMocHelpers::SignalData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cacheCleared'
        QtMocHelpers::SignalData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'handlePresetImagesReceived'
        QtMocHelpers::SlotData<void(const QJsonArray &)>(15, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QJsonArray, 12 },
        }}),
        // Slot 'handleImageDownloaded'
        QtMocHelpers::SlotData<void()>(16, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'handleNetworkError'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError)>(17, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 8 },
        }}),
        // Method 'loadImage'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(19, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 20 },
        }}),
        // Method 'loadImage'
        QtMocHelpers::MethodData<void(const QString &)>(19, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Method 'loadPresetImage'
        QtMocHelpers::MethodData<void(const QString &)>(21, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'loadPresetImagesFromDatabase'
        QtMocHelpers::MethodData<void(bool)>(22, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 23 },
        }}),
        // Method 'loadPresetImagesFromDatabase'
        QtMocHelpers::MethodData<void()>(22, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'getCachedImagePath'
        QtMocHelpers::MethodData<QString(const QString &)>(24, 4, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 5 },
        }}),
        // Method 'getCachedImageFileUrl'
        QtMocHelpers::MethodData<QString(const QString &)>(25, 4, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 5 },
        }}),
        // Method 'hasPresetImage'
        QtMocHelpers::MethodData<bool(const QString &)>(26, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'getPresetImageUrl'
        QtMocHelpers::MethodData<QString(const QString &)>(27, 4, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'getPresetImageFileUrl'
        QtMocHelpers::MethodData<QString(const QString &)>(28, 4, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 10 },
        }}),
        // Method 'clearCache'
        QtMocHelpers::MethodData<void()>(29, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'preloadCommonImages'
        QtMocHelpers::MethodData<void()>(30, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ImageLoader, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ImageLoader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ImageLoaderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ImageLoaderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ImageLoaderE_t>.metaTypes,
    nullptr
} };

void ImageLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ImageLoader *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->imageLoaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->imageLoadFailed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->presetImageLoaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->presetImagesFromDatabaseLoaded((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 4: _t->presetImagesReady(); break;
        case 5: _t->cacheCleared(); break;
        case 6: _t->handlePresetImagesReceived((*reinterpret_cast< std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 7: _t->handleImageDownloaded(); break;
        case 8: _t->handleNetworkError((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 9: _t->loadImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 10: _t->loadImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->loadPresetImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->loadPresetImagesFromDatabase((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->loadPresetImagesFromDatabase(); break;
        case 14: { QString _r = _t->getCachedImagePath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->getCachedImageFileUrl((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->hasPresetImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->getPresetImageUrl((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->getPresetImageFileUrl((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->clearCache(); break;
        case 20: _t->preloadCommonImages(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ImageLoader::*)(const QString & , const QString & )>(_a, &ImageLoader::imageLoaded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImageLoader::*)(const QString & , const QString & )>(_a, &ImageLoader::imageLoadFailed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImageLoader::*)(const QString & , const QString & )>(_a, &ImageLoader::presetImageLoaded, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImageLoader::*)(const QJsonArray & )>(_a, &ImageLoader::presetImagesFromDatabaseLoaded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImageLoader::*)()>(_a, &ImageLoader::presetImagesReady, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImageLoader::*)()>(_a, &ImageLoader::cacheCleared, 5))
            return;
    }
}

const QMetaObject *ImageLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ImageLoaderE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImageLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void ImageLoader::imageLoaded(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void ImageLoader::imageLoadFailed(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void ImageLoader::presetImageLoaded(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void ImageLoader::presetImagesFromDatabaseLoaded(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ImageLoader::presetImagesReady()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ImageLoader::cacheCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
