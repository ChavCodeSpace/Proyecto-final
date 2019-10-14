#include "instruccion.h"
#include "ui_instruccion.h"
#include "menu.h"

Instruccion::Instruccion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instruccion)
{
    ui->setupUi(this);
}

Instruccion::~Instruccion()
{
    delete ui;
}

void Instruccion::on_Atras_clicked()
{
    this->hide();
    Menu *m = new Menu();
    m->setModal(true);
    m->show();
}
