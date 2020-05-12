#include "tearthperson.h"

TEarthPerson::TEarthPerson() {
    myMagic = "Earth";
}

void TEarthPerson::setupCurPerson() {
    img = QImage(":/Images/pacman.png").scaled(cellSize, cellSize);
}
