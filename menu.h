#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "game.h"
#include "player.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_MultiPlayer_clicked();

    void on_Instrucciones_clicked();

    void on_Salir_clicked();

    void on_OnePlayer_clicked();

private:
    Ui::Menu *ui;
    Game *game;
    QList<Player *> listUser;
};

#endif // MENU_H
