#include "tfireperson.h"

TFirePerson::TFirePerson() {
    myMagic = "Fire";
}

void TFirePerson::setupCurPerson() {
    img = QImage(":/sonic.png").scaled(cellSize, cellSize);
}
