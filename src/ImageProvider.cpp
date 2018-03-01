//
// Created by Masahiro Hirano on 2018/02/28.
//

#include "ImageProvider.h"
#include <opencv2/opencv.hpp>
#include <QDebug>

ImageProvider::ImageProvider(QObject* parent ) :
        QObject(parent),
        QQuickImageProvider(QQuickImageProvider::Pixmap),
        image(QPixmap(400,400))
{
    image.scaled(400,400,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    image.fill(QColor(QLatin1String("gray")));
    std::cout << "constructor called";
}


QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize){
    Q_UNUSED(size);
    Q_UNUSED(requestedSize);
    return image;
}

void ImageProvider::onLoadImageButtonPressed(){
    qDebug() << "Button pressed from C++";
}
