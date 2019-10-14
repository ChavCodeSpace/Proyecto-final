#include "loginsolo.h"
#include "ui_loginsolo.h"
#include "game.h"
#include "menu.h"
#include "dialoglog.h"
#include <QDebug>

LoginSolo::LoginSolo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginSolo)
{
    ui->setupUi(this);
}

LoginSolo::~LoginSolo()
{
    delete ui;
}

bool LoginSolo::validarUsuario(QString username, QString password)
{
    for(int i=0;i<listUser.size();i++){
        Player *userTemp = listUser.at(i);
        qDebug()<<userTemp->getName()<<":"<<userTemp->getPass();
        if(userTemp->getName()==username){
            if(userTemp->getPass()==password){
                return true;
            }
        }
    }
    return false;
}

void LoginSolo::createUser(QString &username, QString &pass)
{
    Player *play = new Player();
    play->setName(username);
    play->setPass(pass);
    listUser.append(play);
}

void LoginSolo::setVal(QString *usern, QString *passw)
{
    username = *usern;
    pass = *passw;
}

void LoginSolo::setListUser(QList<Player *> listUser)
{
    this->listUser = listUser;
}

void LoginSolo::on_aceptar_clicked()
{
    QString username = ui->nameus->text();
    QString pass = ui->pasus->text();
    createUser(username,pass);
    if(validarUsuario(username,pass)){
        QMessageBox::information(this,"Login", "Usuario Correcto");
        this->hide();
        Game *game = new Game();
        game->show();
    }else{
        QMessageBox::information(this,"Login", "Usuario incorrecto");
    }
}

void LoginSolo::on_atras_clicked()
{
    this->hide();
    DialogLog *w = new DialogLog();
    w->setModal(true);
    w->show();
}
