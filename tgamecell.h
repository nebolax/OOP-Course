#ifndef TGAMECELL_H
#define TGAMECELL_H

#include <QObject>
#include <QIcon>
#include <QLabel>

#include "tperson.h"
#include "tartefact.h"
#include "tfirstartefact.h"
#include "tsecondartefact.h"

class TGameCell : public QObject
{
    Q_OBJECT
public:
    explicit TGameCell();
    void setup(int cs, int mapSize, QPoint posPix, TPerson *person, QWidget *par, bool withArtefact=false);
    virtual void procMove();

protected:
    QWidget *parent = new QWidget();
    TPerson *person = new TPerson();
    QLabel *view = new QLabel();
    QImage img = QImage();
    QPoint myPos = QPoint();
    int cellSize = 0;
    int strength = 0;
    int mapSize = 0;
    virtual void setupCurStih();
    void paintStrength();
private:
    bool isArtefact = false;
    TArtefact *artf = new TArtefact();

private slots:
    void teleportSlot(QPoint target);
    void swapKeysSlot(QList<int> swaps);

signals:
    void loseGameSignal();
    void winGameSignal();
    void teleportSignal(QPoint target);
    void swapKeysSignal(QList<int> swaps);
};

#endif // TGAMECELL_H
