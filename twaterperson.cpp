#include "twaterperson.h"

TWaterPerson::TWaterPerson() {
    myMagic = "Water";
}

void TWaterPerson::setupCurPerson() {
    img = QImage(":/Images/mario.png").scaled(cellSize, cellSize);

}
