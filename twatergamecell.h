#ifndef TWATERGAMECELL_H
#define TWATERGAMECELL_H

#include <QObject>
#include "tgamecell.h"

class TWaterGameCell : public TGameCell
{
    Q_OBJECT
public:
    TWaterGameCell();
    void setupCurStih() override;
    void procMove() override;

};

#endif // TWATERGAMECELL_H
