#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPixmap>
#include <opencv2/opencv.hpp>

#include "ImageProvider.h"

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ImageProvider ip;
    engine.addImageProvider(QLatin1String("imageProvider"), &ip); // should be loaded before qml file

    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* root = engine.rootObjects().first();

//    QObject::connect(
//            root, // sender
//            SIGNAL(loadImageButtonPressed()), // signal
//            &imageProvider , // receiver
//            SLOT(onLoadImageButtonPressed()) // slot
//    );
//    QObject::connect(
//            root,
//            SIGNAL(exitButtonPressed()),
//            &app,
//            SLOT(quit())
    //);

    return app.exec();
}
