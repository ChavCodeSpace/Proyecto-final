#include <QApplication>
#include "game.h"
#include "menu.h"
#include "dialoglog.h"

/*
Juego de Pinbal, desarrollado para la materia de informatica 2, en el 2019-1
*/

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    DialogLog *w = new DialogLog();//Esta es la ventana principal de registro de usuarios
    w->setModal(true);//Para que sea una ventana emergente
    w->show();//se muestra la ventana

    return a.exec();
}
