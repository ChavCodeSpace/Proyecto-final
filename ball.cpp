#include "ball.h"
#include <QDebug>
#include "game.h"
#include <math.h>
#define PI 3.14159265

//Bola para multijugador

//Medidas de la escena
#define WIDTH 500.0
#define HEIGHT 700.0

extern Game * game;

Ball::Ball(QGraphicsItem * parent):QObject(),QGraphicsPixmapItem ()
{
    qsrand(time(NULL));
    vx=(6+qrand()%(10-6))*pow(2,1/2)/2;
    vy=(6+qrand()%(10-6))*pow(2,1/2)/2;
    setPixmap(QPixmap(":/imagenes/bola.png"));
    setPos(250,350);
    setTransformOriginPoint(0,0);

}

void Ball::advance(int phase)
{
    // No hay colisión:
    if(scene()->collidingItems(this).isEmpty())
    {
        pos_x_antes_colision=x();
        pos_y_antes_colision=y();
        circulo();
    }
    // Si hay colisión:
    else
    {
        qDebug()<<x();
        qDebug()<<y();
        qDebug()<<vx;
        qDebug()<<vy;

        // Pendiente bola
        pendiente_bola=(y()-pos_y_antes_colision)/(x()-pos_x_antes_colision);

        // Pared superior
        if ((0<=x()&&x()<=500)&&(110<=y()&&y()<=125)) {
            vy=-vy;
            // Actualizando posición despues de colisión
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Pared inferior
        if ((0<=x()&&x()<=500)&&(530<=y()&&y()<=570)) {
            vy=-vy;
            // Actualizando posición despues de colisión
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Pared derecha
        if((455<=x()&&x()<=500)&&(120<=y()&&y()<=580)){
            vx=-vx;
            // Actualizando posición despues de colisión
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Pared izquierda
        if((-55<=x()&&x()<=2)&&(120<=y()&&y()<=580)){
            vx=-vx;
            // Actualizando posición despues de colisión
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Palanca jugador 1 y 2 en posición abajo
        if((70<=y() && y()<=115) || (540<=y() && y()<=595) ){
           vx=-vx;
           vy=-vy;
           // Actualizando posición despues de colisión
           qreal dt = 1;
           setX(x() + vx*dt);
           setY(y() + vy*dt);
           setPos(x(),y());
        }
        //--------- Obstaculo 1 --------------
        // Derecha
        if((60<=x() && x()<=86)&&(404<=y() && y()<=486)){
            vx=-vx;
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Izquierda
        if((20<=x()&&x()<=35)&&(404<=y()&&y()<=486)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Superior
        if((35<=x()&&x()<=80)&&(410<=y()&&y()<=420)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Inferior
        if((35<=x()&&x()<=80)&&(458<=y()&&y()<=468)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }

        //--------- Obstaculo 1b -------------
        // Derecha
        if((427<=x()&&x()<=440)&&(230<=y()&&y()<=284)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Izquierda
        if((375<=x()&&x()<=397)&&(230<=y()&&y()<=284)){
            vx=-vx;
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Inferior
        if((384<=x()&&x()<=457)&&(285<=y()&&y()<=296)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Superior
        if((384<=x()&&x()<=457)&&(210<=y()&&y()<=230)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }

        //--------- Obstaculo 2 --------------

        // Superior
        if((290<=x()&&x()<=374)&&(410<=y()&&y()<=418)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Inferior
        if((290<=x()&&x()<=374)&&(460<=y()&&y()<=474)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }

        // Derecha
        if((365<=x()&&x()<=377)&&(417<=y()&&y()<=466)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Izquierda
        if((275<=x()&&x()<=290)&&(417<=y()&&y()<=466)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //--------- Obstaculo 2b--------------
        //Superior
        if((30<=x()&&x()<=120)&&(210<=y()&&y()<=221)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //Inferior
        if((30<=x()&&x()<=120)&&(260<=y()&&y()<=274)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //Izquierda
        if((20<=x()&&x()<=30)&&(220<=y()&&y()<=270)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Derecha
        if((110<=x()&&x()<=120)&&(220<=y()&&y()<=270)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }

        //--------- Eliminar bola y contar punto -------------
        if(650<=y()&&y()<=720){
            //Player::addPoint()
        }

//        else {
//            // Actualizando posición despues de colisión
//            qreal dt = 1;
//            setX(x() + vx*dt);
//            setY(y() + vy*dt);
//            setPos(x(),y());
//        }
    }
}

// Movimiento físicos
// Rectilineo
void Ball::recta(void){
    qreal dt = 1;
    setX(x() + vx*dt);
    setY(y() + vy*dt);
    setPos(x(),y());
}
// Circular
void Ball::circulo(void){
    static qreal dt = 1;
    //setX(x()+2*sin(dt));
    setX(x()+vx);
    setY(y()+2*cos(dt));
    setY(y()+0.3);
    setPos(x(),y());
    dt+=0.1;
}

