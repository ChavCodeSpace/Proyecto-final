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

    vx=8*pow(2,1/2)/2;
    vy=8*pow(2,1/2)/2;
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
        qDebug()<<vx;
        qDebug()<<vy;

        // Pendiente bola
        pendiente_bola=(y()-pos_y_antes_colision)/(x()-pos_x_antes_colision);

        // Pared inferior y superior; y palancas arribas
        if ((535<=y()&&y()<=550) ||( (110<=y()&&y()<=130))) {
            // Pendiente pared
            pendiente_obstaculo=0;
            // Angulo de colisión
            angulo_colision=atan2(pendiente_bola-pendiente_obstaculo,1+pendiente_bola*pendiente_obstaculo)* 180 / PI;
            // Magnitud de la velocidad
            velocidad=sqrt((vx*vx)+(vy*vy));
            // Solo cambia la dirección de la velocidad en y
            if(vx>=0)
                vy=-velocidad*sin(angulo_colision*PI/180);
            else
                vy=velocidad*sin(angulo_colision*PI/180);
            // Actualizando posición despues de colisión
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Pared derecha e izquierda
        if((455<=x()&&x()<=465) || (-10<=x()&&x()<=5)){
            // Pendiente pared
            pendiente_obstaculo=0;
            // Angulo de colisión
            angulo_colision=atan2(pendiente_bola-pendiente_obstaculo,1+pendiente_bola*pendiente_obstaculo)* 180 / PI;
            // Magnitud de la velocidad
            velocidad=sqrt((vx*vx)+(vy*vy));
            // Solo cambia la dirección de la velocidad en y
            if(vy>=0)
                vx=-velocidad*sin(angulo_colision*PI/180);
            else
                vx=velocidad*sin(angulo_colision*PI/180);
            // Actualizando posición despues de colisión
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        // Palanca jugador 1 y 2 en posición abajo
        if((0<y() && y()<100) || (540<y() && y()<595) ){
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
        if((60<=x() && x()<=70)&&(410<=y() && y()<=425)){
            vx=-vx;
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }


        //--------- Obstaculo 1b -------------
        // Derecha
        if((430<=x()&&x()<=440)&&(230<=y()&&y()<=245)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //--------- Obstaculo 2 --------------
        // Arriba
        if((300<=x()&&x()<=330)&&(410<=y()&&y()<=415)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //--------- Obstaculo 2b--------------
        //Izquierda
        if((70<=x()&&x()<=115)&&(210<=y()&&y()<=230)){
            vx=-vx;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //Inferior
        if((60<=x()&&x()<=80)&&(260<=y()&&y()<=275)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
        }
        //Superior
        if((60<=x()&&x()<=80)&&(220<=y()&&y()<=235)){
            vy=-vy;
            qreal dt = 1;
            setX(x() + vx*dt);
            setY(y() + vy*dt);
            setPos(x(),y());
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

