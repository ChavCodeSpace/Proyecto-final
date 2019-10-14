#include <QApplication>
#include "game.h"
#include "menu.h"

/*
Tutorial Topics:
-QGraphicsPixmapItem, QPixmap, QImage
*/

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    Menu *w = new Menu();
    w->setModal(true);
    w->show();

    return a.exec();
}
