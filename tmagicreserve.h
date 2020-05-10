#ifndef TMAGICRESERVE_H
#define TMAGICRESERVE_H

#include <QString>
#include <QColor>
#include <QProgressBar>

class TMagicReserve
{
public:
    TMagicReserve(QString name) {id = name;
                                pbar->setTextVisible(false);}
    void updateValue(int nval) {value = nval;
                                pbar->setValue(value);}
    QString id = "";
    QColor color = QColor::fromRgb(0, 0, 0);
    QProgressBar *pbar = new QProgressBar();

    int value = 0;
};

#endif // TMAGICRESERVE_H
