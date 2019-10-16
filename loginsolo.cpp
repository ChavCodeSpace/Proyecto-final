#include "loginsolo.h"
#include "ui_loginsolo.h"
#include "game.h"
#include "gamesolo.h"
#include "menu.h"
#include "dialoglog.h"
#include <QDebug>


//Codigo para el login de un solo jugador

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

//Funcion que recorre la lista y verifica la existencia del usuario
bool LoginSolo::validarUsuario(QString username, QString password)
{
    bool bandera=false;
    for(int i=0;i<listUser.size();i++){
        Player *userTemp = listUser.at(i);
        qDebug()<<userTemp->getName()<<":"<<userTemp->getPass();
        qDebug()<<username;
        if(userTemp->getName()==username){
            if(userTemp->getPass()==password){
                bandera=true;
                //return bandera;
            }
        }
    }
    return bandera;
}

//Funcion para crear un nuevo jugador
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

//Funcion para actualizar la lista de usuarios
void LoginSolo::setListUser(QList<Player *> listUser)
{
    this->listUser = listUser;
}

//El boton aceptar que llama a la funcion para validar usuarios
void LoginSolo::on_aceptar_clicked()
{
    QString username = ui->nameus->text();
    QString pass = ui->pasus->text();
    qDebug()<<"entro a login";
    createUser(username,pass);
    bool bandera_login=validarUsuario(username,pass);
    if(bandera_login==true){
        QMessageBox::information(this,"Login", "Usuario Correcto");
        this->hide();
        GameSolo *game = new GameSolo();
        game->show();
    }else{
        QMessageBox::information(this,"Login", "Usuario incorrecto");
    }

//    QFile archivo("hola1.txt");
//        QString datosExtra = "Esta es la segunda línea";
//        if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
//            QTextStream datosArchivo(&archivo);
//            datosArchivo << "Hola, esta es la primera línea del archivo \n\r";
//            datosArchivo << datosExtra << endl;

//        }
//    archivo.close();
}

//FUncion para volver al menu de crear y logear usuarios
void LoginSolo::on_atras_clicked()
{
    this->hide();
    DialogLog *w = new DialogLog();
    this->setListUser(listUser);
    w->setModal(true);
    w->show();
}
