#include "admin.h"

Admin::Admin(QObject *parent)
    : QObject(parent)
    , login(new Login)
    , ventana(new Ventana)
{
    login->show();

    connect(login, SIGNAL(signal_usuarioValidado()), this, SLOT(slot_usuarioFueValidado()));
}

void Admin::slot_usuarioFueValidado()
{
    login->hide();
    ventana->show();
}
