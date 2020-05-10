#include "tfinishgamecell.h"

TFinishGameCell::TFinishGameCell() : TGameCell()
{

}

void TFinishGameCell::setupCurStih() {
    img = QImage(":/finishFlag.jpg").scaled(cellSize, cellSize);
}

void TFinishGameCell::procMove() {
    emit winGameSignal();
}
