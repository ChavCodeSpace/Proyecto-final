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
    QString getPass() const;
    void setPass(const QString &value);

private:
    QString name;
    QString pass;
    int points;
    QList<Player *> listUser;
};

#endif // PLAYER_H
