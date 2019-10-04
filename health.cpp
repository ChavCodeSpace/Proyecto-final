#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem (parent)
{
    // Iniciando con 3 vidas
    health=3;

    // Dibujar el texto
    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ")+QString::number(health));
}

int Health::getHealth()
{
    return health;
}

