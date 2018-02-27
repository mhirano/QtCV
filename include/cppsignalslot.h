//
// Created by Masahiro Hirano on 2018/02/27.
//

#ifndef QTCV_CPPSIGNALSLOT_H
#define QTCV_CPPSIGNALSLOT_H

#include <QObject>

class CppSignalSlot: public QObject {
    Q_OBJECT

public:
    explicit CppSignalSlot(QObject *parent = 0);
    
signals:
    void cppSignal(QString text);

public slots:

    void cppSlot(QString msg);
};

#endif //QTCV_CPPSIGNALSLOT_H
