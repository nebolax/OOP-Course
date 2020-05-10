#ifndef TFIREGAMECELL_H
#define TFIREGAMECELL_H

#include <QObject>
#include "tgamecell.h"

class TFireGameCell : public TGameCell
{
    Q_OBJECT
public:
    TFireGameCell();
    void setupCurStih() override;
    void procMove() override;

};

#endif // TFIREGAMECELL_H
