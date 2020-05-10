#ifndef TFIREPERSON_H
#define TFIREPERSON_H

#include <QObject>
#include "tperson.h"

class TFirePerson : public TPerson
{
public:
    TFirePerson();

private:
    void setupCurPerson() override;
};

#endif // TFIREPERSON_H
