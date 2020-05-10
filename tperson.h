#ifndef TPERSON_H
#define TPERSON_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QLabel>
#include <QGridLayout>
#include <iostream>

#include "tmagicreserve.h"

class TPerson
{
public:
    TPerson();
    void makeMove(QPoint dpos); // delta position
    void teleport(QPoint npos); // new position
    void setup(QPoint fieldPosition, int cs, QPoint persPos, QWidget *par);  // fieldPos - пиксели, persPos - клетки
    void addMagic(QString magicName);
    void updateMagic(QString magicName, int value);
    int magicLevel(QString magicName);
    QList<QString> magicsList();
    QString personMsh(); // person's membership
    QPoint position();
    int x();
    int y();


protected:
    int strength = 0;
    int cellSize = 0;
    QString myMagic = "";
    QImage img = QImage();
    virtual void setupCurPerson();
    virtual void paintReserves();

private:
    QWidget *parent = new QWidget();
    QWidget *canvas = new QWidget();
    QPoint fieldPos = QPoint();
    QPoint myPos = QPoint();
    QLabel *view = new QLabel();

    void repaint();
    QList<TMagicReserve> magics = QList<TMagicReserve>();
};

#endif // TPERSON_H
