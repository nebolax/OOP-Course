#include "tenemy.h"

TEnemy::TEnemy() : QObject()
{

}

void TEnemy::setup(QPoint enemyPos, QPoint fieldPix, int cellSize, QWidget *parent) {
    myPos = enemyPos;
    fieldPos = fieldPix;
    this->parent = parent;
    this->cellSize = cellSize;
    view = new QLabel(parent);
    view->show();
    setupCurEnemy();
    view->setPixmap(QPixmap::fromImage(img));
    repaint();
}

void TEnemy::setupCurEnemy() {
    img = QImage(":/Images/emptyCell.png");
}

void TEnemy::moveEnemy(QPoint move) {
    //аа дикие умные алгоритмы
    myPos += move;
    repaint();
}

QPoint TEnemy::getMove(QPoint persPos) {
    QPoint move = curEnemyMove(persPos);
    return move;
}

QPoint TEnemy::position() {
    return myPos;
}

QPoint TEnemy::curEnemyMove(QPoint persPos) {
    QPoint res = QPoint(0, 0);
    int way = qrand() % 4;
    switch (way) {
    case 0:
        res = QPoint(1, 0);
        break;
    case 1:
        res = QPoint(0, 1);
        break;
    case 2:
        res = QPoint(-1, 0);
        break;
    case 3:
        res = QPoint(0, -1);
        break;
    default:
        break;
    }
    return res;
}

void TEnemy::repaint() {
    view->setGeometry(fieldPos.x()+myPos.x()*cellSize, fieldPos.y()+myPos.y()*cellSize, cellSize, cellSize);
}
