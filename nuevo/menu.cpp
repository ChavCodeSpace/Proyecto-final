#include "menu.h"
#include "mainwindow.h"
#include "form.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    f=new Form();
    connect(f, &Form::finalizo,this,&Menu::show);
    f->show();
    this->hide();
}

void Menu::on_pushButton_2_clicked()
{

}
