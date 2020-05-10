#ifndef TGAMEMECH_H
#define TGAMEMECH_H

#include <QObject>
#include <QMainWindow>
#include <QKeyEvent>
#include <iostream>

#include "tperson.h"
#include "tartefact.h"
#include "tgamecell.h"
#include "tenemy.h"
#include "tfinishgamecell.h"
#include "tfiregamecell.h"
#include "twatergamecell.h"
#include "tearthgamecell.h"
#include "tfireperson.h"
#include "twaterperson.h"
#include "tearthperson.h"
#include "tfirstenemy.h"
#include "tsecondenemy.h"

class TGameMech : public QWidget
{
    Q_OBJECT
public:
    explicit TGameMech();

private:
    QList<QList<TGameCell*>> genMap();

    QList<QList<TGameCell*>> wholeMap = QList<QList<TGameCell*>>();

    int cellSize = 80; // Размер одной клетки
    int mapCount = 8; // Размер карты (карта квадратная)
    bool playing = true;
    int finY = 0;
    QPoint fieldPos = QPoint();

    void procMove(int curKey);

    TPerson *person = new TPerson();
    QPoint persPos = QPoint();
    QList<QPoint> enemiesPos = QList<QPoint>();

    void keyPressEvent(QKeyEvent *event) override;

    QList<int> moveKeys = QList<int>();  // 0-up, 1-left, 2-down, 3-right

    QList<TEnemy*> enemies = QList<TEnemy*>();


private slots:
    void loseGameSlot();
    void winGameSlot();
    void teleportSlot(QPoint target);
    void swapKeysSlot(QList<int> swaps);

};

#endif // TGAMEMECH_H
