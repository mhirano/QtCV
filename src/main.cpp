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

    ImageProvider *imageProvider = new ImageProvider;

    engine.addImageProvider(QLatin1String("imageProviderChannel"), imageProvider); // should be loaded before qml file
    
    engine.rootContext()->setContextProperty("imageProvider", imageProvider); // not 

    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* root = engine.rootObjects().first();

    return app.exec();
    
}
