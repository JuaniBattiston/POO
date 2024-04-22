#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , window (new Window)
{
    ui->setupUi(this);
    ui->leUser->setFocus();

    connect(ui->pbLogin, SIGNAL(pressed()), this, SLOT(slot_validate_user()));
    connect(ui->lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validate_user()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validate_user()
{
    if (ui->leUser->text() == "admin" && ui->lePassword->text() == "1234") {
        this->hide();
        window->show();
    } else {
        this->close();
    }
}
