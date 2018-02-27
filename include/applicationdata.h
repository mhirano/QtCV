//
// Created by Masahiro Hirano on 2018/02/27.
//

#ifndef QTCV_APPLICATIONDATA_H
#define QTCV_APPLICATIONDATA_H

#include <QObject>
#include <QString>

class ApplicationData: public QObject {
    
    Q_OBJECT

public:

    Q_INVOKABLE QString getTextFromCpp(){
        return QString("This is the text from C++");
    }
};

#endif //QTCV_APPLICATIONDATA_H
