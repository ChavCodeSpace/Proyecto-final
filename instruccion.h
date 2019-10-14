#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include <QDialog>

namespace Ui {
class Instruccion;
}

class Instruccion : public QDialog
{
    Q_OBJECT

public:
    explicit Instruccion(QWidget *parent = nullptr);
    ~Instruccion();

private slots:
    void on_Atras_clicked();

private:
    Ui::Instruccion *ui;
};

#endif // INSTRUCCION_H
