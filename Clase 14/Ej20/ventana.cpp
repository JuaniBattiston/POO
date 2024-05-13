#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    ui->widget->setText("Hola Mundo");
    ui->widget->colorear(Boton::Color::BLUE);
    ui->widget_2->setText("Hola Mundo 2");
    ui->widget_2->colorear(Boton::Color::RED);
    ui->widget_3->setText("Hola Mundo 3");
    ui->widget_3->colorear(Boton::Color::GREEN);
    ui->widget_4->setText("Hola Mundo 4");
    ui->widget_5->setText("Hola Mundo 5");
}

Ventana::~Ventana()
{
    delete ui;
}
