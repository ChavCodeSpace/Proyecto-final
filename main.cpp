#include <QApplication>
#include "game.h"
#include "menu.h"
#include "dialoglog.h"

/*
Tutorial Topics:
-QGraphicsPixmapItem, QPixmap, QImage
*/

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    DialogLog *w = new DialogLog();
    w->setModal(true);
    w->show();

    return a.exec();
}
