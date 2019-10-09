#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Obstaculo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstaculo();
};

#endif // OBSTACULO_H
