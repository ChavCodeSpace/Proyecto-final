#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Form::finish);
}

Form::~Form()
{
    delete ui;
}

void Form::finish()
{
    emit finalizo();
    this->close();
}
