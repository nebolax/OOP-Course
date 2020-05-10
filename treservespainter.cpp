#include "treservespainter.h"

TReservesPainter::TReservesPainter(QWidget *parent): QWidget(parent)
{

}

void TReservesPainter::paint(QList<TMagicReserve> magres) {
    gl = new QGridLayout();
    int width = 80;
    int height = magres.size()*30;
}
