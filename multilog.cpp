#include "multilog.h"
#include "dialoglog.h"
#include "nuevousuario.h"
#include "ui_multilog.h"
#include "menu.h"
#include <QDebug>

//Funcion para el login de dos usuarios, para el modo versus

MultiLog::MultiLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultiLog)
{
    ui->setupUi(this);

    //varaiables para comprobar que ambos usuarios logueen antes de jugar
    stateUser1 = false;
    stateUser2 = false;
}

MultiLog::~MultiLog()
{
    delete ui;
}

//Funcion para validar usuarios, que recorre la lista de los jugadores para ver si existen o no
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

//crear jugador
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

//boton pque crea una ventana para el registro de un nuevo usuario, si se amerita
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
    if(stateUser1&&stateUser2){//Si ambos usuarios loguearon con exito, pueden jugar
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
        stateUser1 = true;//Si el usuario existe en la lista cambia el valor de la bandera
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
        stateUser2 = true;//Si el usuario existe en la lista cambia el valor de la bandera
    }else{
        QMessageBox::information(this,"Login", "Usuario incorrecto");
    }
}

//boton para volver al menu principal
void MultiLog::on_atras_clicked()
{
    this->hide();
    Menu *w = new Menu();
    this->setListUser(listUser);
    w->setModal(true);
    w->show();

}
