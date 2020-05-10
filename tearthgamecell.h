#ifndef TEARTHGAMECELL_H
#define TEARTHGAMECELL_H

#include <QObject>
#include "tgamecell.h"

class TEarthGameCell : public TGameCell
{
    Q_OBJECT
public:
    TEarthGameCell();
    void setupCurStih() override;
    void procMove() override;

};

#endif // TEARTHGAMECELL_H
