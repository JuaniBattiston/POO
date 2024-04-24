#include "ventana.h"
#include "ui_ventana.h"
#include <QGridLayout>
#include <QDebug>

Ventana::Ventana(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    if (!image.load("sunset.jpg")) {
        qDebug() << "Error loading image";
    }

    ldni = new QLabel("DNI:");
    lName = new QLabel("Nombre:");
    lFamilyName = new QLabel("Apellido:");
    ledni = new QLineEdit();
    leName = new QLineEdit();
    leFamilyName = new QLineEdit();
    pbAddUser = new QPushButton("Añadir");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ldni, 0, 0);
    layout->addWidget(ledni, 0, 1);
    layout->addWidget(lName, 1, 0);
    layout->addWidget(leName, 1, 1);
    layout->addWidget(lFamilyName, 2, 0);
    layout->addWidget(leFamilyName, 2, 1);
    layout->addWidget(pbAddUser, 3, 0, 1, 2);

    setLayout(layout);
    
    connect(pbAddUser, SIGNAL(pressed()), this, SLOT(slot_add_user()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    int x = (this->width() - this->width()* 0.5) / 2;
    int y = (this->height() - this->width()* 0.5) / 2;

    if (!image.isNull()) {
        p.drawImage(x, y, image.scaled(this->width()-this->width()*0.5, this->height()-this->height()*0.5));
    }

    p.setPen(QColor(Qt::black));
    p.drawRect(x, y, this->width()-this->width()*0.5, this->height()-this->height()*0.5);

}

void Ventana::slot_add_user()
{
    qDebug() << "Usuario Subido";
    QCoreApplication::quit();
}
