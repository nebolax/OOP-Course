#include "tfiregamecell.h"

TFireGameCell::TFireGameCell()
{

}

void TFireGameCell::setupCurStih() {
    img = QImage(":/Images/fire.jpg").scaled(cellSize, cellSize);
    person->addMagic("Fire");
    paintStrength();
}

void TFireGameCell::procMove() {
    foreach(QString name, person->magicsList()) {
        int val = person->magicLevel(name)-10*(strength+1);
        person->updateMagic(name, val);
        if(val <= 0) {
            emit loseGameSignal();
        }
    }
}
