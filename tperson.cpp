#include "tperson.h"

TPerson::TPerson()
{

}

void TPerson::setup(QPoint fieldPosition, int cs, QPoint persPos, QWidget *par) {
    fieldPos = fieldPosition;
    cellSize = cs;
    myPos = persPos;
    parent = par;
    strength = qrand() % 3;

    view = new QLabel(parent);
    setupCurPerson();
    view->setPixmap(QPixmap::fromImage(img));
    view->show();
    view->raise();
    repaint();
}

void TPerson::makeMove(QPoint dpos) {
    myPos += dpos;
    repaint();
}

void TPerson::teleport(QPoint npos) {
    myPos = npos;
    repaint();
}

void TPerson::repaint() {
    view->setGeometry(fieldPos.x()+myPos.x()*cellSize, fieldPos.y()+myPos.y()*cellSize, cellSize, cellSize);
    paintReserves();
}

void TPerson::setupCurPerson() {
    img = QImage(":/emptyCell.png");
}

void TPerson::addMagic(QString magicName) {
    bool isMagic = false;
    for(int i = 0; i < magics.size(); i++) {
        if(magics[i].id == magicName) {
            isMagic = true;
            break;
        }
    }
    if(!isMagic) {
        magics.append(TMagicReserve(magicName));
        magics.last().updateValue(100);
        magics.last().pbar->setStyleSheet("color: blue;");
        repaint();
    }
}

void TPerson::updateMagic(QString magicName, int value) {
    for(int i = 0; i < magics.size(); i++) {
        if(magics[i].id == magicName) {
            magics[i].updateValue(value);
            break;
        }
    }
    repaint();
}

int TPerson::magicLevel(QString magicName) {
    for(int i = 0; i < magics.size(); i++) {
        if(magics[i].id == magicName) {
            return magics[i].value;
        }
    }
    return -1;
}

void TPerson::paintReserves() {
    canvas->close();
    canvas = new QWidget(parent);
    int width = 160;
    int height = magics.size()*30;
    canvas->setGeometry(view->x()-width, view->y()-height, width, height);
    canvas->show();

    for(int i = 0; i < magics.size(); i++) {
        QLabel *bgl = new QLabel(canvas);
        bgl->setGeometry(0, 30*i, 160, 25);
        bgl->setStyleSheet("background-color: red;");
        bgl->show();
        QLabel *progBar = new QLabel(canvas);
        progBar->setGeometry(0, 30*i, 160*((double)magics[i].value/100.0), 25);
        progBar->setStyleSheet("background-color: blue;");
        progBar->show();
        QLabel *label = new QLabel(canvas);
        label->setText(magics[i].id);
        label->setGeometry(0, 30*i, 160, 25);
        label->setStyleSheet("font-size: 20px;"
                             "color: yellow;"
                             "border: 2px solid yellow;");
        label->show();
    }
    canvas->raise();
}

QString TPerson::personMsh() {
    return myMagic;
}

QList<QString> TPerson::magicsList() {
    QList<QString> res = QList<QString>();
    for(int i = 0; i < magics.size(); i++) {
        res.append(magics[i].id);
    }
    return res;
}

QPoint TPerson::position() {
    return myPos;
}

int TPerson::x() {
    return myPos.x();
}

int TPerson::y() {
    return myPos.y();
}
