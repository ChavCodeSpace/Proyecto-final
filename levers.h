#ifndef LEVERS_H
#define LEVERS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Levers:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Levers();
};

#endif // LEVERS_H
