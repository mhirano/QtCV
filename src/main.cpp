#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPixmap>
#include <opencv2/opencv.hpp>

#include "Image.h"
// #include "ImageProvider.h"


using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* root = engine.rootObjects().first();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    engine.addImageProvider(QLatin1String("imageProvider"), new ImageProvider);

    Image img;

    QObject::connect(
            root, // sender
            SIGNAL(loadImageButtonPressed()), // signal
            &img, // receiver
            SLOT(onLoadImageButtonPressed()) // slot
    );

//    Mat lena = imread( "qrc:/../res/lena.png", IMREAD_COLOR );

//    cvtColor(lena, lena, COLOR_BGR2RGB );

//    QPixmap qLena = QPixmap::fromImage(QImage((unsigned char*) lena.data, lena.cols, lena.rows, QImage::Format_RGB888));




    return app.exec();
}
