#ifndef TEARTHPERSON_H
#define TEARTHPERSON_H

#include <QObject>
#include "tperson.h"

class TEarthPerson : public TPerson
{
public:
    TEarthPerson();

private:
    void setupCurPerson() override;
};

#endif // TEARTHPERSON_H
