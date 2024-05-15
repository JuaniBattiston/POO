#include "ventana.h"
#include "ui_ventana.h"
#include "login.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    pbGoBack = new QPushButton("Volver", this);

    connect(pbGoBack, &QPushButton::clicked, this, &Ventana::slot_go_back);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::set_login(Login *login)
{
    this->login = login;
}


void Ventana::slot_go_back()
{
    this->hide();
    login->show();
}
