#include "nuevousuario.h"
#include "ui_nuevousuario.h"
#include "player.h"
#include "menu.h"
#include "loginsolo.h"
#include "dialoglog.h"
#include <QDebug>

NuevoUsuario::NuevoUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevoUsuario)
{
    ui->setupUi(this);
}

NuevoUsuario::~NuevoUsuario()
{
    delete ui;
}

void NuevoUsuario::on_aceptar_clicked()
{
    QString name = ui->name->text();
    QString pass = ui->pass->text();
    //qDebug() << name<<":"<<pass;
    LoginSolo *log = new LoginSolo();
    log->createUser(name,pass);
    log->setListUser(listUser);
    this->hide();
    Menu *w = new Menu();
    w->setModal(true);
    w->show();
}

void NuevoUsuario::on_atras_clicked()
{
    this->hide();
    DialogLog *w = new DialogLog();
    w->setModal(true);
    w->show();

}
