#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Manager)
    , login(new Login)
{
    ui->setupUi(this);
    login->show();

    connect(login, SIGNAL(signal_login()), this, SLOT(slot_handle_login()));
}

Manager::~Manager()
{
    delete ui;
}

void Manager::slot_handle_login()
{
    login->hide();
    this->show();
}
