#ifndef DIALOGLOG_H
#define DIALOGLOG_H

#include <QDialog>
#include "player.h"

namespace Ui {
class DialogLog;
}

class DialogLog : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLog(QWidget *parent = nullptr);
    ~DialogLog();

private slots:
    void on_nju_clicked();

    void on_exju_clicked();

    void on_atras_clicked();

private:
    Ui::DialogLog *ui;
    QList<Player *> listUser;
};

#endif // DIALOGLOG_H
