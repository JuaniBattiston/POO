#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    lMessage = new QLabel();
    lMessage->setAlignment(Qt::AlignCenter);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lMessage, 0, 0);

    setLayout(layout);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::setBienvenida(QString message)
{
    lMessage->setText(message);
}
