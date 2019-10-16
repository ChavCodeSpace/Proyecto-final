#ifndef BALLONEPLAYER_H
#define BALLONEPLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <vector>
#include <iostream>
#include <math.h>
#include <QGraphicsScene>



class Balloneplayer: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Balloneplayer(QGraphicsItem * parent=0);
public slots:
    void advance(int phase);
private:
    qreal vx;
    qreal vy;
    qreal velocidad;
    // Vector de posición
    qreal pos_x_antes_colision;
    qreal pos_y_antes_colision;
    // Pendientes
    qreal pendiente_bola;
    qreal pendiente_obstaculo;
    // Angulo de la colision
    qreal angulo_colision;
    // Movimientos físicos
    void recta(void);
    void circulo(void);
};

#endif // BALLONEPLAYER_H
