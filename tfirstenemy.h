#ifndef TFIRSTENEMY_H
#define TFIRSTENEMY_H

#include <QObject>
#include "tenemy.h"

class TFirstEnemy : public TEnemy
{
    Q_OBJECT
public:
    TFirstEnemy();
    void setupCurEnemy() override;

private:
    QPoint curEnemyMove(QPoint persPos) override;

signals:

};

#endif // TFIRSTENEMY_H
