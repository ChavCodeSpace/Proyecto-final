#ifndef LOGMULTI_H
#define LOGMULTI_H

#include <QDialog>

namespace Ui {
class Logmulti;
}

class Logmulti : public QDialog
{
    Q_OBJECT

public:
    explicit Logmulti(QWidget *parent = nullptr);
    ~Logmulti();

private:
    Ui::Logmulti *ui;
};

#endif // LOGMULTI_H
