//
// Created by Masahiro Hirano on 2018/03/02.
//

#include "Application.h"

void Application::configure() {
    engine.addImageProvider(QLatin1String("imageProviderChannel"), imageProvider); // should be loaded before qml file
    engine.rootContext()->setContextProperty("imageProvider", imageProvider); // not 
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
}

int Application::exec() {
    configure();
    return app.exec();
}
