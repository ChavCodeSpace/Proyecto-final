#include "logmulti.h"
#include "ui_logmulti.h"

Logmulti::Logmulti(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logmulti)
{
    ui->setupUi(this);
}

Logmulti::~Logmulti()
{
    delete ui;
}
