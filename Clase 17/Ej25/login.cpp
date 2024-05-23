#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->label->setText("Registrar usuario");
    connect(ui->label, SIGNAL(signal_clic()), this, SLOT(slot_label_clicked()));
    connect(ui->pbLogin, SIGNAL(clicked()), this, SLOT(slot_user_logged_in()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_label_clicked() {
    emit signal_register_user();
}

void Login::slot_user_logged_in()
{
    QString user = ui->leUser->text();
    QString pass = ui->lePassword->text();

    QStringList user_data = AdminDB::get_instance()->validate_user("users",user, pass);

    qDebug() << user_data;
    if (user_data.size() == 0) {
        //ui->label->setText("Usuario o contraseña incorrectos");
        return;
    }

    emit signal_user_logged_in();
}
