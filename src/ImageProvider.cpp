//
// Created by Masahiro Hirano on 2018/02/28.
//

#include "ImageProvider.h"

ImageProvider::ImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}


//QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
//    int width = 100;
//    int height = 50;

//    if (size)
//        *size = QSize(width, height);
//    QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
//                   requestedSize.height() > 0 ? requestedSize.height() : height);
//    pixmap.fill(QColor(id).rgba());

//    return pixmap;
//}
