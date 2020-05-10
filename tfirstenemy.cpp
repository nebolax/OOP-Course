#include "tfirstenemy.h"

TFirstEnemy::TFirstEnemy()
{

}

void TFirstEnemy::setupCurEnemy() {
    img = QImage(":/enemy1.png").scaled(cellSize, cellSize);
}

QPoint TFirstEnemy::curEnemyMove(QPoint persPos) {
    QPoint dl = persPos-myPos;
    if(dl.x() != 0) {
        if(dl.x() > 0) {
            return QPoint(1, 0);
        } else {
            return QPoint(-1, 0);
        }
    } else {
        if(dl.y() > 0) {
            return QPoint(0, 1);
        } else {
            return QPoint(0, -1);
        }
    }
    return QPoint(0, 0);
}
