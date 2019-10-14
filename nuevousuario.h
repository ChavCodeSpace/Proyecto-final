#ifndef NUEVOUSUARIO_H
#define NUEVOUSUARIO_H

#include <QDialog>
#include "player.h"

namespace Ui {
class NuevoUsuario;
}

class NuevoUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit NuevoUsuario(QWidget *parent = nullptr);
    ~NuevoUsuario();

private slots:
    void on_aceptar_clicked();

    void on_atras_clicked();

private:
    Ui::NuevoUsuario *ui;
    QString usern;
    QString pass;
    QList<Player *> listUser;
};

#endif // NUEVOUSUARIO_H
