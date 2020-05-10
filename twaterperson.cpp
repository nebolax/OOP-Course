#include "twaterperson.h"

TWaterPerson::TWaterPerson() {
    myMagic = "Water";
}

void TWaterPerson::setupCurPerson() {
    img = QImage(":/mario.png").scaled(cellSize, cellSize);

}
