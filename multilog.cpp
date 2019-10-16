#include "multilog.h"
#include "dialoglog.h"
#include "nuevousuario.h"
#include "ui_multilog.h"
#include "menu.h"
#include <QDebug>

MultiLog::MultiLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultiLog)
{
    ui->setupUi(this);

    stateUser1 = false;
    stateUser2 = false;
}

MultiLog::~MultiLog()
{
    delete ui;
}

bool MultiLog::validarUsuario(QString username, QString password)
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

void MultiLog::createUser(QString &username, QString &pass)
{
    Player *play = new Player();
    play->setName(username);
    play->setPass(pass);
    listUser.append(play);
}

void MultiLog::setVal(QString *usern, QString *passw)
{
    username = *usern;
    pass = *passw;
}

void MultiLog::setListUser(QList<Player *> listUser)
{
    this->listUser = listUser;
}

void MultiLog::on_newusr_clicked()
{
    this->hide();
    NuevoUsuario *np = new NuevoUsuario();
    this->setListUser(listUser);
    np->setModal(true);
    np->show();
}

void MultiLog::on_play_clicked()
{
    if(stateUser1&&stateUser2){
        this->hide();
        Game *game = new Game();
        game->show();
    }else{
        QMessageBox::warning(this,"Error","Aún no puede iniciar la partida hasta que los dos usuarios inicien sesion");
    }

}

void MultiLog::on_aceptar1_clicked()
{
    QString username = ui->name1->text();
    QString pass = ui->pass1->text();
    createUser(username,pass);
    if(validarUsuario(username,pass)){
        QMessageBox::information(this,"Login", "Usuario Correcto");
        stateUser1 = true;
    }else{
        QMessageBox::information(this,"Login", "Usuario incorrecto");
    }
}

void MultiLog::on_aceptar2_clicked()
{
    QString username = ui->name2->text();
    QString pass = ui->pass2->text();
    createUser(username,pass);
    if(validarUsuario(username,pass)){
        QMessageBox::information(this,"Login", "Usuario Correcto");
        stateUser2 = true;
    }else{
        QMessageBox::information(this,"Login", "Usuario incorrecto");
    }
}

void MultiLog::on_atras_clicked()
{
    this->hide();
    Menu *w = new Menu();
    this->setListUser(listUser);
    w->setModal(true);
    w->show();

}
