#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

#include "mediaplayer.h"


#ifdef Q_OS_ANDROID
#include <QtAndroid>

void permissionCallback(const QtAndroid::PermissionResultMap &res) {
    if (res["android.permission.READ_EXTERNAL_STORAGE"] == QtAndroid::PermissionResult::Denied)
        QGuiApplication::exit();
}
#endif


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    MediaPlayer mediaplayer;
    engine.rootContext()->setContextProperty("mediaplayer", &mediaplayer);

    return app.exec();
}
