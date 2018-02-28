//
// Created by Masahiro Hirano on 2018/02/28.
//

#ifndef QTCV_IMAGE_H
#define QTCV_IMAGE_H

#include <QObject>

class Image : public QObject{

Q_OBJECT

public:
    explicit Image(QObject *parent = nullptr);

public slots:
    void onLoadImageButtonPressed();
};


#endif //QTCV_IMAGE_H
