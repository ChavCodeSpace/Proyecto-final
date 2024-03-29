#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "ball.h"
#include "levers.h"
#include "health.h"
#include "obstaculo.h"
#include "player.h"
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class Game:public QGraphicsView
{
   //Q_OBJECT

public:
    Game(QWidget * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

    //probando repositorio

    // ESCENA
    QGraphicsScene * scene;
    // BOLA
    Ball *ball;
    //JUGADOR 1
    Player *jugador_1;
    Levers *left_lever_player_1;
    Levers *right_lever_player_1;
    int left_angle_player_1=0;
    int right_angle_player_1=0;
    //JUGADOR 2
    Player *jugador_2;
    Levers *left_lever_player_2;
    Levers *right_lever_player_2;
    int left_angle_player_2=0;
    int right_angle_player_2=0;
    // VIDAS
    Health *health;
    //OBSTACULOS
    Obstaculo *obs1;
    Obstaculo *obs1b;
    Obstaculo *obs2;
    Obstaculo *obs2b;
    Obstaculo *estrella;
    //timer
    QTimer * timer;
    //arduino
    QSerialPort *serial;
    QString portName;
    quint16 vendorrId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();

private slots:
    void serial_read();
};

#endif // GAME_H
