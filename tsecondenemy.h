#ifndef TSECONDENEMY_H
#define TSECONDENEMY_H

#include <QObject>
#include "tenemy.h"

class TSecondEnemy : public TEnemy
{
    Q_OBJECT
public:
    TSecondEnemy();
    void setupCurEnemy() override;

private:
    QPoint curEnemyMove(QPoint persPos) override;

signals:

};

#endif // TSECONDENEMY_H
