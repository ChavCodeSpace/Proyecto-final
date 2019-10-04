#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>

//Medidas de la escena
#define WIDTH 500
#define HEIGHT 700

Game::Game(QWidget *parent){
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

    QPen mypen_rect=QPen(Qt::red);
    mypen_rect.setWidth(5);
    scene->addLine(0,HEIGHT-120,WIDTH/3,HEIGHT-120,mypen_rect);
    scene->addLine(WIDTH-WIDTH/3,HEIGHT-120,WIDTH,HEIGHT-120,mypen_rect);
    scene->addLine(0,120,WIDTH,120,mypen_rect);
    // Crear bola
    ball = new Ball();
    scene->addItem(ball);

    // Crear palanca izquierda

    left_lever= new Levers();
    left_lever->setPixmap(QPixmap(":/imagenes/palanca.png"));
    left_lever->setPos(WIDTH/3,HEIGHT-120);
    scene->addItem(left_lever);
    QTransform t_left;
    t_left.translate(0,0).rotate(45);
    left_lever->setTransform(t_left);

    left_lever->setFlag(QGraphicsItem::ItemIsFocusable);
    left_lever->setFocus();

    // Crear palanca derecha
    right_lever= new Levers();
    right_lever->setPixmap(QPixmap(":/imagenes/palanca.png"));
    right_lever->setPos(WIDTH-WIDTH/3,HEIGHT-120);
    scene->addItem(right_lever);

    QTransform t_right;
    t_right.translate(0,0).rotate(135);
    right_lever->setTransform(t_right);

    // Crear numero de vidas
    health = new Health();
    health->setPos(health->x()+10,health->y()+10);
    scene->addItem(health);

    show();

    //Conectar
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer->start(20);
}

void Game::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Left){
        left_angle+=45;
        left_lever->setRotation(-left_angle);
    }
    if (event->key() ==Qt::Key_Right ) {
       right_angle=45;
       right_lever->setRotation(right_angle);
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{

    if (event->key() ==Qt::Key_Left) {
        left_angle=0;
        left_lever->setRotation(left_angle);
    }
    if (event->key() ==Qt::Key_Right ) {
        right_angle=0;
        right_lever->setRotation(right_angle);
     }
}
