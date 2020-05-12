#include "tsecondenemy.h"

TSecondEnemy::TSecondEnemy()
{

}

void TSecondEnemy::setupCurEnemy() {
    img = QImage(":/Images/enemy2.png").scaled(cellSize, cellSize);
}

QPoint TSecondEnemy::curEnemyMove(QPoint persPos) {
    QPoint dl = persPos-myPos;
    if(dl.y() != 0) {
        if(dl.y() > 0) {
            return QPoint(0, 1);
        } else {
            return QPoint(0, -1);
        }
    } else {
        if(dl.x() > 0) {
            return QPoint(1, 0);
        } else {
            return QPoint(-1, 0);
        }
    }
    return QPoint(0, 0);
}
