//
// Created by Masahiro Hirano on 2018/02/28.
//

#ifndef QTCV_IMAGEPROVIDER_H
#define QTCV_IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QPixmap>

class ImageProvider : public QQuickImageProvider{
public:
    ImageProvider();
//    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
};

#endif //QTCV_IMAGEPROVIDER_H

