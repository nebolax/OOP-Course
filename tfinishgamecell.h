#ifndef TFINISHCELL_H
#define TFINISHCELL_H

#include <QObject>
#include <QIcon>
#include <QImage>
#include "tgamecell.h"

class TFinishGameCell : public TGameCell
{
    Q_OBJECT
public:
    TFinishGameCell();
    void procMove() override;

protected:
    void setupCurStih() override;

signals:

};

#endif // TFINISHCELL_H
