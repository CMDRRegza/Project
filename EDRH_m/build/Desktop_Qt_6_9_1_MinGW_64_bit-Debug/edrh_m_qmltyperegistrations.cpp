/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<edrhcontroller.h>)
#  include <edrhcontroller.h>
#endif
#if __has_include(<imageloader.h>)
#  include <imageloader.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_EDRH()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<EDRHController>("EDRH", 1);
    qmlRegisterTypesAndRevisions<ImageLoader>("EDRH", 1);
    QT_WARNING_POP
    qmlRegisterModule("EDRH", 1, 0);
}

static const QQmlModuleRegistration eDRHRegistration("EDRH", qml_register_types_EDRH);
