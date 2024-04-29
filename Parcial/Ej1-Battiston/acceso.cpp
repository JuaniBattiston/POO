#include "acceso.h"
#include "ui_acceso.h"

#include <QDebug>

Acceso::Acceso(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Acceso)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    loginAttempts = 0;
    this->setMaximumSize(400, 200);

    this->setWindowTitle("Login de Usuarios");
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_download_finished(QNetworkReply*)));
    connect(ui->pbLogin, SIGNAL(pressed()), this, SLOT(slot_validate_user()));
    connect(ui->lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validate_user())); //por comodidad

    manager->get(QNetworkRequest(QUrl("https://i.pinimg.com/736x/ab/27/12/ab27120b156c4ea6b995b9c64c754cae.jpg")));
}

Acceso::~Acceso()
{
    delete ui;
}

void Acceso::slot_download_finished(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    repaint();
    image.save("image.jpg");

    show();
}
void Acceso::slot_validate_user()
{
    QString user = ui->leUser->text();
    QString pass = ui->lePassword->text();

    if(user == "admin" && pass == "1234"){
        hide();
        ventana = new Ventana();
        ventana->setBienvenida(QString("Hola " + user));
        ventana->show();
    }
    else if (user == "user" && pass == "4321") {
        hide();
        ventana = new Ventana();
        ventana->setBienvenida(QString("Hola " + user));
        ventana->show();
    } else {
        loginAttempts++;
        if (loginAttempts >= 3) {
            QApplication::quit();
        }

        ui->lePassword->clear();
    }
}
void Acceso::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if(!image.isNull()){
        p.drawImage(0, 0, image.scaled(this->width(), this->height(), Qt::KeepAspectRatioByExpanding));
    }
}
