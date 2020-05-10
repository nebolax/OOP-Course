#ifndef TSECONDARTEFACT_H
#define TSECONDARTEFACT_H

#include <QObject>
#include "tartefact.h"

class TSecondArtefact : public TArtefact
{
    Q_OBJECT
public:
    TSecondArtefact();
    void procMove() override;

private:
    void setupCurArtefact() override;

signals:

};

#endif // TSECONDARTEFACT_H
