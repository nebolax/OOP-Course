#include "tfirstartefact.h"

TFirstArtefact::TFirstArtefact()
{

}

void TFirstArtefact::setupCurArtefact() {
    QImage whole = QImage(":/animation3.png");
    for(int i = 0; i < 5    ; i++) {
        for(int a = 0; a < 6; a++) {
            QImage curImg = QImage(100, 100, QImage::Format_ARGB32);
            for(int j = 0; j < 100; j++) {
                for(int c = 0; c < 100; c++) {
                    curImg.setPixelColor(j, c, whole.pixelColor(i*100 + j, a*100 + c));
                }
            }
            curImg = curImg.scaled(cellSize, cellSize);
            animation.append(curImg);
        }
    }
}

void TFirstArtefact::procMove() {
    QList<int> repl = QList<int>() << 1 << 0 << 3 << 2;
    emit swapKeysSignal(repl);
}
