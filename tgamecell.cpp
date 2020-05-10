#include "tgamecell.h"

TGameCell::TGameCell() : QObject(){

}

void TGameCell::setup(int cs, int mapSize, QPoint posPix, TPerson *person, QWidget *par, bool withArtefact) { // pos - в пикселях
    isArtefact = withArtefact;
    this->person = person;
    this->mapSize = mapSize;
    parent = par;
    cellSize = cs;
    myPos = posPix;
    strength = qrand() % 3;
    view = new QLabel(parent);
    view->setGeometry(posPix.x(), posPix.y(), cellSize, cellSize);
    view->show();
    if(!isArtefact) {
        setupCurStih();
        view->setPixmap(QPixmap::fromImage(img));
        view->setStyleSheet("background-color: #AAAAAA;"
                            "border: 1px solid white;");
    } else {
        int diffArtefacts = 2;
        int artIndex = qrand() % diffArtefacts;
        switch (artIndex) {
        case 0:
            artf = new TFirstArtefact();
            break;
        case 1:
            artf = new TSecondArtefact();
            break;
        default:
            break;
        }
        view->setStyleSheet("background-color: #AAAAAA;"
                            "border: 1px solid white;");
        connect(artf, &TArtefact::teleportSignal, this, &TGameCell::teleportSlot);
        connect(artf, &TArtefact::swapKeysSignal, this, &TGameCell::swapKeysSlot);
        artf->setup(view->geometry(), cellSize, mapSize,  person, parent);
    }

}

void TGameCell::setupCurStih() {
    img = QImage(":/white.png").scaled(cellSize, cellSize);
    person->addMagic("NoneMagic");
}

void TGameCell::paintStrength() {
    QLabel *strengthLab = new QLabel(parent);
    switch (strength) {
    case 0:
        strengthLab->setText("Low");
        strengthLab->setGeometry(myPos.x()+(cellSize-40)/2, myPos.y()+(cellSize-20-5), 40, 20);
        break;
    case 1:
        strengthLab->setText("Mid");
        strengthLab->setGeometry(myPos.x()+(cellSize-40)/2, myPos.y()+(cellSize-20)/2, 40, 20);
        break;
    case 2:
        strengthLab->setText("High");
        strengthLab->setGeometry(myPos.x()+(cellSize-40)/2, myPos.y()+5, 40, 20);
        break;
    default:
        break;
    }
    strengthLab->setStyleSheet("color: red;"
                               "font-size: 20px;"
                               "text-align: top center;"
                               "background-color: white;");
    strengthLab->setAlignment(Qt::AlignCenter);
    strengthLab->show();
    strengthLab->raise();
}

void TGameCell::procMove() {
    if(isArtefact) {
        artf->procMove();
    }
}

void TGameCell::teleportSlot(QPoint target) {
    emit teleportSignal(target);
}

void TGameCell::swapKeysSlot(QList<int> swaps) {
    emit swapKeysSignal(swaps);
}
