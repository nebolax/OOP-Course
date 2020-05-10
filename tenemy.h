#ifndef TENEMY_H
#define TENEMY_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QLabel>

class TEnemy : public QObject
{
    Q_OBJECT
public:
    explicit TEnemy();
    void setup(QPoint enemyPos, QPoint fieldPix, int cellSize, QWidget *parent);
    virtual void setupCurEnemy();
    void moveEnemy(QPoint move);
    QPoint getMove(QPoint persPos);
    QPoint position();

protected:
    QPoint myPos = QPoint();
    QWidget *parent = new QWidget();
    QLabel *view = new QLabel();
    QImage img = QImage();
    QPoint fieldPos = QPoint();
    int cellSize = 0;
    virtual QPoint curEnemyMove(QPoint persPos);
    void repaint();

signals:
    void loseGameSignal();
};

#endif // TENEMY_H
