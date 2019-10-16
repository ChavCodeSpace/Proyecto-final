#include "dialoglog.h"
#include "ui_dialoglog.h"
#include "nuevousuario.h"
#include "loginsolo.h"
#include "menu.h"

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

void DialogLog::on_nju_clicked()
{
    this->hide();
    NuevoUsuario *nplay = new NuevoUsuario();
    nplay->setModal(true);
    nplay->show();
}

void DialogLog::on_exju_clicked()
{
    this->hide();
    LoginSolo *log = new LoginSolo();
    log->setListUser(listUser);
    log->setModal(true);
    log->show();
}

void DialogLog::on_atras_clicked()
{
    this->hide();
    Menu *m = new Menu();
    m->setModal(true);
    m->show();
}
