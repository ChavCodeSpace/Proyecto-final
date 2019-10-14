#ifndef LOGINSOLO_H
#define LOGINSOLO_H

#include <QDialog>
#include "player.h"
#include <QMessageBox>

namespace Ui {
class LoginSolo;
}

class LoginSolo : public QDialog
{
    Q_OBJECT

public:
    explicit LoginSolo(QWidget *parent = nullptr);
    ~LoginSolo();
    bool validarUsuario(QString username, QString password);
    void createUser(QString &username, QString &pass);
    QList<Player*> getList();
    void setVal(QString *usern, QString *passw);
    void actualizarListUser();
    void setListUser(QList<Player*> listUser);

private slots:
    void on_aceptar_clicked();

    void on_atras_clicked();

private:
    Ui::LoginSolo *ui;
    QList<Player*> listUser;
    QString username;
    QString pass;

};

#endif // LOGINSOLO_H
