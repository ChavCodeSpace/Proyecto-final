#include "player.h"
#include <QFont>

Player::Player(QGraphicsItem *parent): QGraphicsTextItem (parent)
{
    name=" ";
    points=0;

    setPlainText(name+":"+QString::number(points)+QString("pts"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
}

QString Player::getName() const
{
    return name;
}

void Player::setName(const QString &value)
{
    this->name = value;
}

void Player::updatePlayer()
{
    setPlainText(name+":"+QString::number(points)+QString("pts"));
}

void Player::addPoint()
{
    points++;
    setPlainText(name+":"+QString::number(points)+QString("pts"));
}

QString Player::getPass() const
{
    return pass;
}

void Player::setPass(const QString &value)
{
    pass = value;
}
