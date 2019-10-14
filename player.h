#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsTextItem>
#include <QString>

class Player: public QGraphicsTextItem
{
public:
    Player(QGraphicsItem * parent=0);
    QString getName() const;
    void setName(const QString &value);
    void updatePlayer();
    void addPoint();
private:
    QString name;
    int points;
};

#endif // PLAYER_H
