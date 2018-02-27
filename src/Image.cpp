//
// Created by Masahiro Hirano on 2018/02/28.
//

#include <iostream>
#include <opencv2/opencv.hpp>

#include "Image.h"

Image::Image(QObject *parent) : QObject(parent){

}

void Image::loadImageButtonPressed() {
    std::cout << "hoge";
}