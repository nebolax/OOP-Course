#include "tfinishgamecell.h"

TFinishGameCell::TFinishGameCell() : TGameCell()
{

}

void TFinishGameCell::setupCurStih() {
    img = QImage(":/Images/finishFlag.jpg").scaled(cellSize, cellSize);
}

void TFinishGameCell::procMove() {
    emit winGameSignal();
}
