#ifndef TFIRSTARTEFACT_H
#define TFIRSTARTEFACT_H

#include <QObject>
#include "tartefact.h"

class TFirstArtefact : public TArtefact
{
    Q_OBJECT
public:
    TFirstArtefact();
    void procMove() override;
private:
    void setupCurArtefact() override;

signals:

};

#endif // TFIRSTARTEFACT_H
