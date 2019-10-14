#include "ball.h"
#include <QDebug>
#include "game.h"
#include <math.h>
#define PI 3.14159265

//Medidas de la escena
#define WIDTH 500.0
#define HEIGHT 700.0

extern Game * game;

Ball::Ball(QGraphicsItem * parent):QObject(),QGraphicsPixmapItem ()
{
    vx=10*pow(2,1/2)/2;
    vy=10*pow(2,1/2)/2;
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
        recta();
    }
    // Si hay colisión:
    else
    {
        qDebug()<<x();
        qDebug()<<y();
        // Pendiente bola
        pendiente_bola=(y()-pos_y_antes_colision)/(x()-pos_x_antes_colision);

        // Pared inferior y superior
        if (y()== 540 || y()== 115) {
            // Pendiente pared
            pendiente_obstaculo=0;
            // Angulo de colisión
            angulo_colision=atan2(pendiente_bola-pendiente_obstaculo,1+pendiente_bola*pendiente_obstaculo)* 180 / PI;
            // Magnitud de la velocidad
            velocidad=sqrt((vx*vx)+(vy*vy));
            // Solo cambia la velocidad en y
            if(vx>=0)
                vy=-velocidad*sin(angulo_colision*PI/180);
            else
                vy=velocidad*sin(angulo_colision*PI/180);
            // Actualizando posición despues de colisión
//            qreal dt = 1;
//            setX(x() + vx*dt);
//            setY(y() + vy*dt);
//            setPos(x(),y());
        }
        // Pared derecha e izquierda
        if(x()==460 || x()==0){
            // Pendiente pared
            pendiente_obstaculo=0;
            // Angulo de colisión
            angulo_colision=atan2(pendiente_bola-pendiente_obstaculo,1+pendiente_bola*pendiente_obstaculo)* 180 / PI;
            // Magnitud de la velocidad
            velocidad=sqrt((vx*vx)+(vy*vy));
            // Solo cambia la velocidad en y
            if(vy>=0)
                vx=-velocidad*sin(angulo_colision*PI/180);
            else
                vx=velocidad*sin(angulo_colision*PI/180);
            // Actualizando posición despues de colisión
//            qreal dt = 1;
//            setX(x() + vx*dt);
//            setY(y() + vy*dt);
//            setPos(x(),y());
        }


        // Obstaculo Palanca
        if (x()==295 && y()==535) {
            // Pendiente pared
            pendiente_obstaculo=0;
            //qDebug()<<pendiente_bola;
            angulo_colision=atan2(pendiente_bola-pendiente_obstaculo,1+pendiente_bola*pendiente_obstaculo)* 180 / PI;
            // Magnitud de la velocidad
            velocidad=sqrt((vx*vx)+(vy*vy));
            // Solo cambia la velocidad en y
            if(vx>=0)
                vy=-velocidad*sin(angulo_colision*PI/180);
            else
                vy=velocidad*sin(angulo_colision*PI/180);
            // Actualizando posición despues de colisión
//            qreal dt = 1;
//            setX(x() + vx*dt);
//            setY(y() + vy*dt);
//            setPos(x(),y());
        }

        if(x()==255 && y()==575){
            // Pendiente pared
            pendiente_obstaculo=-1;
            //qDebug()<<pendiente_bola;
            angulo_colision=atan2(pendiente_bola-pendiente_obstaculo,1+pendiente_bola*pendiente_obstaculo)* 180 / PI;
//            qDebug()<<x();
//            qDebug()<<y();
//            qDebug()<<pos_x_antes_colision;
//            qDebug()<<pos_y_antes_colision;
//            qDebug()<<"angulo:";
//            qDebug()<<angulo_colision;
            // Magnitud de la velocidad
            velocidad=sqrt((vx*vx)+(vy*vy));
            // Solo cambia la velocidad en y
            //if(angulo_colision==qreal(90.0)){
                vx=--vx;
                vy=-vy;
            //}
        }

        // Actualizando posición despues de colisión
        qreal dt = 1;
        setX(x() + vx*dt);
        setY(y() + vy*dt);
        setPos(x(),y());

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

