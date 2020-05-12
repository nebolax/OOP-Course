#include "tsecondartefact.h"
#include <iostream>

TSecondArtefact::TSecondArtefact() {

}

void TSecondArtefact::setupCurArtefact() {
    QImage whole = QImage(":/Images/animation2.png");
    for(int i = 0; i < 5; i++) {
        for(int a = 0; a < 6; a++) {
            QImage curImg = QImage(147, 140, QImage::Format_ARGB32);
            for(int j = 0; j < 147; j++) {
                for(int c = 0; c < 140; c++) {
                    curImg.setPixelColor(j, c, whole.pixelColor(i*147 + j, a*140 + c));
                }
            }
            curImg = curImg.scaled(cellSize, cellSize);
            animation.append(curImg);
        }
    }
}

void TSecondArtefact::procMove() {
    QPoint target = QPoint(qrand() % mapSize, qrand() % mapSize);
    emit teleportSignal(target);
}
