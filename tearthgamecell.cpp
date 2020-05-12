#include "tearthgamecell.h"

TEarthGameCell::TEarthGameCell()
{

}

void TEarthGameCell::setupCurStih() {
    img = QImage(":/Images/earth.jpg").scaled(cellSize, cellSize);
    person->addMagic("Earth");
    paintStrength();
}

void TEarthGameCell::procMove() {
    if(person->personMsh() == "Earth") {
        QList<QString> wholeMagics = person->magicsList();
        for(int i = 0; i < wholeMagics.size(); i++) {
            person->updateMagic(wholeMagics[i], person->magicLevel(wholeMagics[i])-5*strength);
        }
    }
}
