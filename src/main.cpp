#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPixmap>

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    if (engine.rootObjects().isEmpty())
        return -1;

    Mat lena = imread( "../res/lena.png",IMREAD_COLOR );
    std::cout << lena.channels();
    std::cout << lena.rows;


    cvNamedWindow("win");
    imshow("win", lena);

    cvtColor(lena, lena, CV_BGR2RGB);

//    QPixmap qLena;
//    qLena = QPixmap::fromImage(QImage((unsigned char*) lena.data, lena.cols, lena.rows, QImage::Format_RGB888));


    return app.exec();
}
