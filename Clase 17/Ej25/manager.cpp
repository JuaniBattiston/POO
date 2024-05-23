#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Manager)
    , login(new Login)
    , register_user(new Register)
    , database_viewer(new DatabaseViever)
{
    ui->setupUi(this);

    login->show();

    connect(this->login, SIGNAL(signal_user_logged_in()), this, SLOT(slot_user_logged_in()));
    connect(this->login, SIGNAL(signal_register_user()), this, SLOT(slot_register_user()));
    connect(this->register_user, SIGNAL(signal_user_registered()), this, SLOT(slot_register_to_login()));
}

Manager::~Manager()
{
    delete ui;
}

void Manager::slot_user_logged_in()
{
    qDebug() << "User logged in";
    login->hide();
    database_viewer->show();
}

void Manager::slot_register_user()
{
    login->hide();
    register_user->show();
}

void Manager::slot_register_to_login()
{
    register_user->hide();
    login->show();
}
