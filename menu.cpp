#include "menu.h"
#include "ui_menu.h"
#include "game.h"
#include "instruccion.h"
#include "nuevousuario.h"
#include "dialoglog.h"
#include "multilog.h"
#include "loginsolo.h"

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

void Menu::on_MultiPlayer_clicked()
{
    this->hide();
    MultiLog *np = new MultiLog();
    np->setModal(true);
    np->show();
}

void Menu::on_Instrucciones_clicked()
{
    this->hide();
    Instruccion *ins = new Instruccion();
    ins->setModal(true);
    ins->show();
}

void Menu::on_Salir_clicked()
{
    this->close();
}

void Menu::on_OnePlayer_clicked()
{
    this->hide();
    LoginSolo *np = new LoginSolo();
    np->setModal(true);
    np->show();
}
