#include "dialoglog.h"
#include "ui_dialoglog.h"
#include "nuevousuario.h"
#include "loginsolo.h"
#include "menu.h"

//Ventana principal de registro de nuevos usuarios y logueo de usuarios existentes


DialogLog::DialogLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLog)
{
    ui->setupUi(this);
}

DialogLog::~DialogLog()
{
    delete ui;
}

void DialogLog::on_nju_clicked()//Si es un nuevo usuario
{
    this->hide();//Esta ventana se esconde
    NuevoUsuario *nplay = new NuevoUsuario();//Se crea una nueva ventana para el registro de nuevos usuarios
    nplay->setModal(true);//Que sea una ventana emergente
    nplay->show();//Se muestra
}

void DialogLog::on_exju_clicked()//Si el usuario ya existe
{
    this->hide();//Esta ventana(Dialog) se esconde
    LoginSolo *log = new LoginSolo();//Se crea una ventana para realizar el login
    log->setListUser(listUser);//Actualiza la lista de usuarios
    log->setModal(true);//Que sea una ventana emergente
    log->show();//Se muestra
}

void DialogLog::on_atras_clicked()//Para regresar al menu principal
{
    this->hide();//Esta ventana se esconde
    Menu *m = new Menu();//Se crean una ventana con el menu principal del juego
    m->setModal(true);//Que sea una ventana emergente
    m->show();//Se muestra la ventana
}
