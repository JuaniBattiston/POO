#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->pbLogin, SIGNAL(pressed()), this, SLOT(slot_login()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_login()
{
    AdminDB *db = AdminDB::get_instance();
    if (!ui->leUser->text().isEmpty() && !ui->lePassword->text().isEmpty()) {
        QStringList user_data = db->validate_user("users", ui->leUser->text(), ui->lePassword->text());
        if (user_data.size() > 0) {
            qDebug() << "Login successful";
            emit signal_login();
        } else {
            qDebug() << "Login failed";
        }
    } else {
        qDebug() << "Login failed!";
    }
}
