#include "login.h"
#include "ui_login.h"
#include <QDebug>



Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , window(new Ventana)
{
    ui->setupUi(this);
    ui->leUser->setFocus();

    connect(ui->pbLogin, SIGNAL(pressed()), this, SLOT(slot_validate_user()));
    connect(ui->lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validate_user()));

    db = adminDB.getDB();
    if (adminDB.conectar( "C:\\Users\\juani\\OneDrive\\Escritorio\\POO\\Clase 14\\db.sqlite" ) )
        qDebug() << "Conexion exitosa";
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validate_user()
{
    bool valid_user = false;
    QStringList result = adminDB.validarUsuario(QString("usuarios"),ui->leUser->text(), ui->lePassword->text());
    if (result.size() > 0) {
        valid_user = true;
    }
    if (valid_user) {
        qDebug() << "Usuario válido";
        this->hide();
        window->set_login(this);
        window->show();

    } else {
        qDebug() << "Usuario inválido";
    }
}

