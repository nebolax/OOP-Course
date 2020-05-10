#include "tartefact.h"
#include <iostream>

TArtefact::TArtefact()
{

}

void TArtefact::setup(QRect geom, int cellSize, int mapSize, TPerson *person, QWidget *parent) {
    this->parent = parent;
    this->cellSize = cellSize;
    this->mapSize = mapSize;
    this->person = person;
    setupCurArtefact();
    view = new QLabel(parent);
    view->setGeometry(geom);
    view->show();
    view->raise();
    changeImage();

    timer->setInterval(delta);
    connect(timer, &QTimer::timeout, this, &TArtefact::changeImage);
    timer->start();
}

void TArtefact::changeImage() {
    if(animation.size() > 0) {
        curIndex += 1;
        if(curIndex >= animation.size()) {
            curIndex = 0;
        }
        view->setPixmap(QPixmap::fromImage(animation[curIndex]));
    }
}

void TArtefact::setupCurArtefact() {

}

void TArtefact::procMove() {

}
