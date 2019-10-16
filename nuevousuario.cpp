#include "nuevousuario.h"
#include "ui_nuevousuario.h"
#include "player.h"
#include "menu.h"
#include "loginsolo.h"
#include "dialoglog.h"
#include <QDebug>

//Codigo para el registro de nuevos usuarios

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
    QString name = ui->name->text();//Guarda el texto escrito en el lineEdit en una variable
    QString pass = ui->pass->text();
    //qDebug() << name<<":"<<pass;
    LoginSolo *log = new LoginSolo();
    log->createUser(name,pass);//Crea un nuevo usuario con estos datos
    log->setListUser(listUser);//Actualiza la lista de Usuarios
    this->hide();
    Menu *w = new Menu();
    w->setModal(true);
    w->show();
}

void NuevoUsuario::on_atras_clicked()//Se devuelve a la ventana de creacion y registro de usuarios
{
    this->hide();
    DialogLog *w = new DialogLog();
    w->setModal(true);
    w->show();

}
