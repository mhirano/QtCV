//
// Created by Masahiro Hirano on 2018/02/28.
//

#ifndef QTCV_IMAGEPROVIDER_H
#define QTCV_IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QPixmap>
#include <QObject>

class ImageProvider : public QObject, public QQuickImageProvider {

    Q_OBJECT
public:
    ImageProvider(QObject* parent = 0);

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

signals:
    void imageChanged();
    
public slots:
    void onLoadImageButtonClicked();

private:
    QPixmap image;

};


#endif //QTCV_IMAGEPROVIDER_H
