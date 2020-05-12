#include "tfireperson.h"

TFirePerson::TFirePerson() {
    myMagic = "Fire";
}

void TFirePerson::setupCurPerson() {
    img = QImage(":/Images/sonic.png").scaled(cellSize, cellSize);
}
