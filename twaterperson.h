#ifndef TWATERPERSON_H
#define TWATERPERSON_H

#include <QObject>
#include "tperson.h"

class TWaterPerson : public TPerson
{
public:
    TWaterPerson();

private:
    void setupCurPerson() override;
};

#endif // TWATERPERSON_H
