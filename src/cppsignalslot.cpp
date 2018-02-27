//
// Created by Masahiro Hirano on 2018/02/27.
//

#include "cppsignalslot.h"
#include <QDebug>

CppSignalSlot::CppSignalSlot(QObject *parent) : QObject(parent){
    
}

void CppSignalSlot::cppSlot(QString msg) {
    qDebug() << "cppSlot is called with the message" << msg;
    emit cppSignal(QString("Hello from C++"));
}