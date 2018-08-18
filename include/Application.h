#ifndef QTCV_APPLICATION_H
#define QTCV_APPLICATION_H

#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPixmap>

#include "ImageProvider.h"

class Application {

public:
    Application(int argc, char **argv):
            app(argc, argv),
            engine(),
            imageProvider(new ImageProvider)
    {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }

    int exec();

private:
    void configure();

    QGuiApplication app;
    QQmlApplicationEngine engine;
    ImageProvider* imageProvider;
};


#endif //QTCV_APPLICATION_H
