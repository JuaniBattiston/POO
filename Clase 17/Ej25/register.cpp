#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);

    connect(ui->pbRegister, SIGNAL(clicked()), this, SLOT(slot_register_user()));
}

Register::~Register()
{
    delete ui;
}

void Register::slot_register_user()
{
    QString name = ui->leName->text();
    QString family_name = ui->leFamilyName->text();
    QString user = ui->leUser->text();
    QString pass = ui->lePassword->text();

    QStringList user_data = AdminDB::get_instance()->register_user("users", name, family_name, user, pass);

    qDebug() << user_data;

    if (user_data.size() == 0) {
        //ui->label->setText("Usuario o contraseña incorrectos");
        return;
    }
    qDebug() << "User registered";
    emit signal_user_registered();
}
