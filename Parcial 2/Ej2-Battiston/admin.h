#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "login.h"
#include "ventana.h"
#include "admindb.h"

class Admin : public QObject
{
    Q_OBJECT

public:
    Admin(QObject  *parent = nullptr);

protected slots:
    void slot_usuarioFueValidado();

private:
    Login *login;
    Ventana *ventana;
};
#endif // ADMIN_H
