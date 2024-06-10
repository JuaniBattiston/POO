#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->pbLogin, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
}

Login::~Login()
{
    delete ui;
}

bool Login::validarUsuario(QString username, QString password)
{
    QStringList data = AdminDB::get_instance()->validate_user("usuarios", username, password);
    return data.size() > 0;
}

void Login::slot_validarUsuario()
{
    QString username = ui->leUser->text();
    QString password = ui->lePassword->text();

    if (validarUsuario(username, password))  {
        emit signal_usuarioValidado();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos");
    }
}
