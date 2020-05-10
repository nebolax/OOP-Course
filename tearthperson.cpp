#include "tearthperson.h"

TEarthPerson::TEarthPerson() {
    myMagic = "Earth";
}

void TEarthPerson::setupCurPerson() {
    img = QImage(":/pacman.png").scaled(cellSize, cellSize);
}
