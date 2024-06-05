#include "Teclado.h"

Teclado::Teclado(const QString& marca, double precio, int cantidadDeTeclas)
    : Instrumento(marca, precio), cantidad_de_teclas(cantidadDeTeclas) {}

void Teclado::afinar() const {
    qDebug() << "Afinando teclado";
}

int Teclado::getCantidadDeTeclas() const {
    return cantidad_de_teclas;
}

void Teclado::setCantidadDeTeclas(int cantidadDeTeclas) {
    this->cantidad_de_teclas = cantidadDeTeclas;
}
