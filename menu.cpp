#include "menu.h"
#include "ui_menu.h"
#include "game.h"
#include "instruccion.h"
#include "nuevousuario.h"
#include "dialoglog.h"
#include "multilog.h"
#include "loginsolo.h"

//Menu principal del juego

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

//Boton de VS (versus) que crea una ventana de login para los dos contrincantes
void Menu::on_MultiPlayer_clicked()
{
    this->hide();
    MultiLog *np = new MultiLog();
    np->setModal(true);
    np->show();
}

//Boton para ver las instrucciones del juego
void Menu::on_Instrucciones_clicked()
{
    this->hide();
    Instruccion *ins = new Instruccion();
    ins->setModal(true);
    ins->show();
}

//Boton para cerrar el juego
void Menu::on_Salir_clicked()
{
    this->close();
}

//Boton para el jugador solo, que abre una ventana de login para un solo jugador
void Menu::on_OnePlayer_clicked()
{
    this->hide();
    LoginSolo *np = new LoginSolo();
    np->setModal(true);
    np->show();
}
