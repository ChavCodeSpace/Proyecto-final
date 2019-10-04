#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "ball.h"
#include "levers.h"
#include "health.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

    //probando repositorio

    // Items de la escena
    QGraphicsScene * scene;
    Ball *ball;
    Levers *left_lever;    
    Levers *right_lever;
    int left_angle=0;
    int right_angle=0;
    Health *health;

    QTimer * timer;
};

#endif // GAME_H
