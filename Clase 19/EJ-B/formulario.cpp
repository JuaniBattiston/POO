#include "formulario.h"
#include "ui_formulario.h"

#include "guitarra.h"
#include "viento.h"
#include "teclado.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->cbInstruments->addItems({"Guitarra", "Viento", "Teclado"});

    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(verStock()));
    connect(ui->cbInstruments, SIGNAL(currentIndexChanged(int)), this, SLOT(actualizarFormulario(int)));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(agregarInstrumento()));

    actualizarFormulario(ui->cbInstruments->currentIndex());
}

Formulario::~Formulario()
{
    qDeleteAll(instrumentos);
}

void Formulario::agregarInstrumento()
{
    QString marca = ui->leMarca->text();
    double precio = ui->lePrecio->text().toDouble();

    if (ui->cbInstruments->currentText() == "Guitarra") {
        int cantidadCuerdas = ui->leCCuerdas->text().toInt();
        instrumentos.append(new Guitarra(marca, precio, cantidadCuerdas));
    } else if (ui->cbInstruments->currentText() == "Viento") {
        QString metalUsado = ui->leMetal->text();
        instrumentos.append(new Viento(marca, precio, metalUsado));
    } else if (ui->cbInstruments->currentText() == "Teclado") {
        int cantidadTeclas = ui->leCTeclas->text().toInt();
        instrumentos.append(new Teclado(marca, precio, cantidadTeclas));
    }

    ui->leMarca->clear();
    ui->lePrecio->clear();
    ui->leCCuerdas->clear();
    ui->leCTeclas->clear();
    ui->leMetal->clear();
}

void Formulario::verStock()
{
    for (const auto& instrumento : instrumentos) {
        //print all instruments
        if (Guitarra* guitarra = (Guitarra*)instrumento) {
            qDebug() << "Guitarra: " << guitarra->getMarca() << " - " << guitarra->getPrecio() << " - " << guitarra->getCantidadDeCuerdas();
        } else if (Viento* viento = dynamic_cast<Viento*>(instrumento)) {
            qDebug() << "Viento: " << viento->getMarca() << " - " << viento->getPrecio() << " - " << viento->getMetalUsado();
        } else if (Teclado* teclado = dynamic_cast<Teclado*>(instrumento)) {
            qDebug() << "Teclado: " << teclado->getMarca() << " - " << teclado->getPrecio() << " - " << teclado->getCantidadDeTeclas();
        }
    }
}

void Formulario::actualizarFormulario(int index)
{
    ui->leCCuerdas->setVisible(index == 0);
    ui->leCTeclas->setVisible(index == 2);
    ui->leMetal->setVisible(index == 1);
}
