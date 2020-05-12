#include "tgamemech.h"

TGameMech::TGameMech() : QWidget()
{

}

void TGameMech::startGame() {
    this->resize(800, 730);
    this->show();

    fieldPos = QPoint(160, 90);

    int personsCount = 3;
    int selPerson = qrand() % personsCount;
    int startY = qrand() % mapCount;

    switch (selPerson) {
    case 0:
        person = new TWaterPerson();
        break;
    case 1:
        person = new TFirePerson();
        break;
    case 2:
        person = new TEarthPerson();
        break;
    default:
        break;
    }
    wholeMap = genMap();
    person->setup(fieldPos, cellSize, QPoint(0, startY), this);

    int muchEnemies = 2, diffEnemies = 2;
    for(int i = 0; i < muchEnemies; i++) {
        int enemRand = qrand() % diffEnemies;

        switch (enemRand) {
        case 0:
            enemies.append(new TFirstEnemy());
            break;
        case 1:
            enemies.append(new TSecondEnemy());
            break;
        default:
            break;
        }
        int enemX = person->x(), enemY = person->y();
        while(((enemX-person->x())*(enemX-person->x())+(enemY-person->y())*(enemY-person->y())) < 25 || ((enemX - (mapCount-1))*(enemX - (mapCount-1)) + (enemY-finY)*(enemY-finY)) < 9) {
            enemX = qrand() % mapCount, enemY = qrand() % mapCount;
        }
        enemies.last()->setup(QPoint(enemX, enemY), fieldPos, cellSize, this);
        connect(enemies.last(), &TEnemy::loseGameSignal, this, &TGameMech::loseGameSlot);
    }

    //wholeMap[person->y()][person->x()]->procMove(); // если нужно, чтобы первая клетка не реагировала с персонажем, закомментируйте эту строку
}

void TGameMech::endGame() {
    for(int i = 0; i < mapCount; i++) {
        for(int a = 0; a < mapCount; a++) {
            delete wholeMap[i][a];
        }
    }
    wholeMap = QList<QList<TGameCell*>>();
    fieldPos = QPoint();
    delete person;
    person = new TPerson();
    persPos = QPoint();
    enemiesPos = QList<QPoint>();
    moveKeys = QList<int>();
    for(int i = 0; i < enemies.size(); i++) {
        delete enemies[i];
    }
    enemies = QList<TEnemy*>();
}

QList<QList<TGameCell*>> TGameMech::genMap() {
    QList<QList<TGameCell*>> map;
    for(int i = 0; i < mapCount; i++) {  // перебираем все клетки и выбираем для каждой случайную стихию

        map.append(QList<TGameCell*>());
        for(int a = 0; a < mapCount; a++) {

            int muchVariants = 4; // кол-во различных типов клеток, не считая финиша
            int curCell = qrand() % muchVariants;

            switch (curCell) {  // 3-ий тип - клетка с артефактом, для нее особый setup + нужны connect slot'ов
            case 0:
                map[i].append(new TFireGameCell());
                map[i][a]->setup(cellSize, mapCount, QPoint(fieldPos.x()+a*cellSize, fieldPos.y()+i*cellSize), person, this);
                break;
            case 1:
                map[i].append(new TWaterGameCell());
                map[i][a]->setup(cellSize, mapCount, QPoint(fieldPos.x()+a*cellSize, fieldPos.y()+i*cellSize), person, this);
                break;
            case 2:
                map[i].append(new TEarthGameCell());
                map[i][a]->setup(cellSize, mapCount, QPoint(fieldPos.x()+a*cellSize, fieldPos.y()+i*cellSize), person, this);
                break;
            case 3:
                map[i].append(new TGameCell());
                map[i][a]->setup(cellSize, mapCount, QPoint(fieldPos.x()+a*cellSize, fieldPos.y()+i*cellSize), person, this, true);
                connect(map[i][a], &TGameCell::teleportSignal, this, &TGameMech::teleportSlot);
                connect(map[i][a], &TGameCell::swapKeysSignal, this, &TGameMech::swapKeysSlot);
            default:
                break;
            }
            connect(map[i][a], &TGameCell::loseGameSignal, this, &TGameMech::loseGameSlot);
        }
    }
    finY = qrand() % mapCount;                          // Выбор случайного положения по оси Y клетки финиша
    delete map[finY].last();                            // Удаление ранее находившейся там клетки
    map[finY].last() = new TFinishGameCell();           // И создание финиша
    map[finY].last()->setup(cellSize,mapCount, QPoint(fieldPos.x()+(mapCount-1)*cellSize, fieldPos.y()+finY*cellSize), person, this);
    disconnect(map[finY].last(), &TGameCell::loseGameSignal, this, &TGameMech::loseGameSlot);
    connect(map[finY].last(), &TGameCell::winGameSignal, this, &TGameMech::winGameSlot);

    return map;
}

void TGameMech::procMove(int curKey) {  // обработка нажатия на клавишу (ход всего и вся)
    if(curKey == moveKeys[0] && person->y() > 0) {
        person->makeMove(QPoint(0, -1));
    } else if(curKey == moveKeys[1] && person->x() > 0) { // в этих ифах выбирается, куда пойдет персонаж и ему сообщается об этом
        person->makeMove(QPoint(-1, 0));
    } else if(curKey == moveKeys[2] && person->y() < mapCount-1) {
        person->makeMove(QPoint(0, 1));
    } else if(curKey == moveKeys[3] && person->x() < mapCount-1) {
        person->makeMove(QPoint(1, 0));
    }
    if(moveKeys.contains(curKey)) {                       // тут вызывается обработка хода клетки, на которую пришел персонаж
        wholeMap[person->y()][person->x()]->procMove();   // и происходят ходы врагов
        foreach(TEnemy* enemy, enemies) {
            QPoint move = enemy->getMove(person->position());
            QPoint newPos = enemy->position()+move;
            if(enemy->position() == person->position()) {
                loseGameSlot();
            }
            if(newPos.x() >= 0 && newPos.x() <= mapCount-1 && newPos.y() >= 0 && newPos.y() <= mapCount-1) {
                enemy->moveEnemy(move);
            }
            if(enemy->position() == person->position()) {
                loseGameSlot();
            }
        }
    }
}

void TGameMech::keyPressEvent(QKeyEvent *event) {  // переопределение keyPressEvent для отслеживания нажатий клавиш
    if(playing) {                                  // Как можно заметить, в начале игры пользователю необходимо последовательно нажать на клавишы
        if(moveKeys.size() < 4) {                  // 1-ая up, 2-ая left, 3-я down, 4-я right
            moveKeys.append(event->key());         // После того, как были нажаты 4 клавишы, начинается игра
        } else {
            procMove(event->key());
        }
    } else if(event->key() == Qt::Key_Return) {
        playing = true;
        endGame();
        startGame();
    }
}

void TGameMech::loseGameSlot() {                   // Данный слот вызывается когда персонаж проигрывает
    QLabel *endLabel = new QLabel(this);           // Он может быть вызван клеткой, на которой стоит персонаж или если враг догнал персонажа
    endLabel->setGeometry(200, 200, 800, 400);
    endLabel->setText("YOU LOSE!!!");
    endLabel->setStyleSheet("background-color: red;"
                            "font-size: 96px;");
    endLabel->show();
    playing = false;
}

void TGameMech::winGameSlot() {                  // Если вызывается данный слот, то персонаж победил
    QLabel *endLabel = new QLabel(this);         // В данный момент он вызывается только клеткой финиша
    endLabel->setGeometry(200, 200, 800, 400);
    endLabel->setText("YOU WIN!!!");
    endLabel->setStyleSheet("background-color: green;"
                            "font-size: 96px;");
    endLabel->show();
    playing = false;
}

void TGameMech::teleportSlot(QPoint target) {         // Телепортация персонажа
    person->teleport(target);                         // Происходит по запросу артефакта
    wholeMap[person->y()][person->x()]->procMove();
}

void TGameMech::swapKeysSlot(QList<int> swaps) {  // Изменение клавиш управления
    QList<int> nkeys = QList<int>();              // Происходит по запросу артефакта
    for(int i = 0; i < 4; i++) {                  // swaps - перестановка, то есть изменяются функции уже имеющихся клавиш
        nkeys.append(moveKeys[swaps[i]]);         // но не добавляются новые клавишы в управление
    }
    moveKeys = nkeys;
}
