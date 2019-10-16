#include "gamesolo.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>

//Medidas de la escena
#define WIDTH 500
#define HEIGHT 700

GameSolo::GameSolo(QWidget *parent)
{
    // Creando escena
    scene = new QGraphicsScene();
    // Tamaño de la escena
    scene->setSceneRect(0,0,WIDTH,HEIGHT); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    // Desactivar barras de desplazamiento
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Tamaño fijo
    setFixedSize(WIDTH,HEIGHT);

    // Dibujar bordes de la escena
    QPen mypen = QPen(Qt::red);
    mypen.setWidth(10);
    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);

    // Crear bola
    ballo = new Balloneplayer();
    scene->addItem(ballo);

    QPen mypen_rect=QPen(Qt::red);
    mypen_rect.setWidth(5);
    // OBSTACULOS
    // Obstaculo 1
    obs1 = new Obstaculo();
    obs1->setPixmap(QPixmap(":/imagenes/obstaculo1.png"));
    obs1->setPos(60,HEIGHT-250);
    scene->addItem(obs1);
    // Obstaculo 1b
    //Agregar obstaculos
    obs1b = new Obstaculo();
    obs1b->setPixmap(QPixmap(":/imagenes/obstaculo1b.png"));
    obs1b->setPos(WIDTH-90,250);
    scene->addItem(obs1b);

    //Obstaculos 2
    obs2 = new Obstaculo();
    obs2->setPixmap(QPixmap(":/imagenes/obstaculo2.png"));
    obs2->setPos(WIDTH-180,HEIGHT-250);
    scene->addItem(obs2);

    // Obstaculo 2 b
    //Agregar obstaculos
    obs2b = new Obstaculo();
    obs2b->setPixmap(QPixmap(":/imagenes/obstaculo2b.png"));
    obs2b->setPos(60,250);
    scene->addItem(obs2b);

//    // Bonus Estrella
//    Obstaculo *estrella = new Obstaculo();
//    estrella->setPixmap(QPixmap(":/imagenes/estrella.png"));
//    estrella->setPos(250,250);
//    scene->addItem(estrella);

    // JUGADOR 1
    // Paredes
    scene->addLine(0,HEIGHT-120,WIDTH/3,HEIGHT-120,mypen_rect);
    scene->addLine(WIDTH-WIDTH/3,HEIGHT-120,WIDTH,HEIGHT-120,mypen_rect);
    // Texto en escena
    jugador_1=new Player();
    jugador_1->setPos(jugador_1->x()+10,jugador_1->y()+600);
    jugador_1->setName("Pulga");
    jugador_1->updatePlayer();
    scene->addItem(jugador_1);
    // Crear palanca izquierda
    left_lever_player_1= new Levers();
    left_lever_player_1->setPixmap(QPixmap(":/imagenes/palanca.png"));
    left_lever_player_1->setPos(WIDTH/3,HEIGHT-120);
    scene->addItem(left_lever_player_1);
    QTransform t_left_player_1;
    t_left_player_1.translate(0,0).rotate(45);
    left_lever_player_1->setTransform(t_left_player_1);
    //left_lever_player_1->setFlag(QGraphicsItem::ItemIsFocusable);
    //left_lever_player_1->setFocus();
    // Crear palanca derecha
    right_lever_player_1= new Levers();
    right_lever_player_1->setPixmap(QPixmap(":/imagenes/palanca.png"));
    right_lever_player_1->setPos(WIDTH-WIDTH/3,HEIGHT-120);
    scene->addItem(right_lever_player_1);
    QTransform t_right_player_1;
    t_right_player_1.translate(0,0).rotate(135);
    right_lever_player_1->setTransform(t_right_player_1);


    show();

    //Conectar
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer->start(20);
}

void GameSolo::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        left_angle_player_1+=45;
        left_lever_player_1->setRotation(-left_angle_player_1);
    }
    if (event->key() ==Qt::Key_Right ) {
       right_angle_player_1=45;
       right_lever_player_1->setRotation(right_angle_player_1);
    }
}

void GameSolo::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() ==Qt::Key_Left) {
        left_angle_player_1=0;
        left_lever_player_1->setRotation(left_angle_player_1);
    }
    if (event->key() ==Qt::Key_Right ) {
        right_angle_player_1=0;
        right_lever_player_1->setRotation(right_angle_player_1);
     }
}
