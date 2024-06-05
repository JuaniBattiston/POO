#include "Guitarra.h"

Guitarra::Guitarra(const QString& marca, double precio, int cantidadDeCuerdas)
    : Instrumento(marca, precio), cantidad_de_cuerdas(cantidadDeCuerdas) {}

void Guitarra::afinar() const {
    qDebug() << "Afinando guitarra";
}

int Guitarra::getCantidadDeCuerdas() const {
    return cantidad_de_cuerdas;
}

void Guitarra::setCantidadDeCuerdas(int cantidadDeCuerdas) {
    this->cantidad_de_cuerdas = cantidadDeCuerdas;
}
