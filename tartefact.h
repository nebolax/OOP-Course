#ifndef TARTEFACT_H
#define TARTEFACT_H

#include <QObject>
#include <QTimer>
#include <QLabel>
#include "tperson.h"

class TArtefact : public QObject
{
    Q_OBJECT
public:
    explicit TArtefact();
    void setup(QRect geom, int cellSize, int mapSize, TPerson *person, QWidget *parent);
    virtual void procMove();
protected:
    virtual void setupCurArtefact();
    QList<QImage> animation = QList<QImage>();
    int delta = 100; // милисекунды времени между картинками
    int cellSize = 0;
    int mapSize = 0;
    TPerson *person = new TPerson();
private:
    QTimer *timer = new QTimer();
    int curIndex = 0;
    QLabel *view = new QLabel();
    QWidget *parent = new QWidget();

private slots:
    void changeImage();

signals:
    void teleportSignal(QPoint target);
    void swapKeysSignal(QList<int> replacing);
};

#endif // TARTEFACT_H
