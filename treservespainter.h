#ifndef RESERVESPAINTER_H
#define RESERVESPAINTER_H


#include <QList>
#include <QGridLayout>
#include <tmagicreserve.h>

class TReservesPainter : public QWidget
{
public:
    TReservesPainter(QWidget *parent);
    void paint(QList<TMagicReserve> magres);

private:
    QGridLayout *gl = new QGridLayout();
};

#endif // RESERVESPAINTER_H
