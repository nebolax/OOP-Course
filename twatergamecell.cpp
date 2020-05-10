#include "twatergamecell.h"

TWaterGameCell::TWaterGameCell()
{

}

void TWaterGameCell::setupCurStih() {
    img = QImage(":/water.jpg").scaled(cellSize, cellSize);
    person->addMagic("Water");
    paintStrength();
}

void TWaterGameCell::procMove() {
    //if(person->personMsh() == "Water") {
        int nmagic = person->magicLevel("Water")-10;
        person->updateMagic("Water", nmagic);
        if(nmagic < 0) {
            emit loseGameSignal();
        }
  //  }
}
