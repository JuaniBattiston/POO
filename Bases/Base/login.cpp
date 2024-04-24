#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , manager(new QNetworkAccessManager(this))
    , ventana(new Ventana)
{
    ui->setupUi(this);

    lUsername = new QLabel("Usuario:");
    lPassword = new QLabel("Contraseña:");
    leUsername = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);
    pbAuth = new QPushButton("Ingresar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lUsername, 0, 0);
    layout->addWidget(leUsername, 0, 1);
    layout->addWidget(lPassword, 1, 0);
    layout->addWidget(lePassword, 1, 1);
    layout->addWidget(pbAuth, 2, 0, 1, 2);

    setLayout(layout);

    connect(pbAuth, SIGNAL(pressed()), this, SLOT(slot_validate_user()));
    connect(lePassword, SIGNAL(returnPressed()), this, SLOT(slot_validate_user()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_download_finished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("https://img.freepik.com/foto-gratis/pintura-lago-montana-montana-al-fondo_188544-9126.jpg")));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validate_user() {
    if (leUsername->text() == "admin" && lePassword->text() == "1234"){
        this->hide();
        ventana->show();
    } else {
        lePassword->clear();
    }
}

void Login::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if(!image.isNull()){
        p.drawImage(0, 0, image.scaled(this->width(), this->height(), Qt::KeepAspectRatioByExpanding));
    }
}

void Login::slot_download_finished(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    repaint();
}
