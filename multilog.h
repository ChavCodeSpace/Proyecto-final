#ifndef MULTILOG_H
#define MULTILOG_H

#include <QDialog>
#include "player.h"
#include "game.h"
#include "gamesolo.h"
#include "menu.h"
#include "dialoglog.h"
#include <QMessageBox>

namespace Ui {
class MultiLog;
}

class MultiLog : public QDialog
{
    Q_OBJECT

public:
    explicit MultiLog(QWidget *parent = nullptr);
    ~MultiLog();
    bool validarUsuario(QString username, QString password);
    void createUser(QString &username, QString &pass);
    QList<Player*> getList();
    void setVal(QString *usern, QString *passw);
    void setListUser(QList<Player*> listUser);


private slots:
    void on_newusr_clicked();

    void on_play_clicked();

    void on_aceptar1_clicked();

    void on_aceptar2_clicked();

    void on_atras_clicked();

private:
    Ui::MultiLog *ui;
    QList<Player*> listUser;
    QString username;
    QString pass;

    bool stateUser1,stateUser2;
};

#endif // MULTILOG_H
