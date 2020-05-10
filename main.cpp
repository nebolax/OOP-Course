#include "tgamemech.h"
#include <iostream>

#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime::currentTime().msec()); // setup рандома
    TGameMech mech; // запуск основного класса
    return a.exec();
}
