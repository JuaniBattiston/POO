#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admindb.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool validarUsuario(QString username, QString password);

private slots:
    void slot_validarUsuario();

signals:
    void signal_usuarioValidado();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
