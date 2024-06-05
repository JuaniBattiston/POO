#include "instrumento.h"

Instrumento::Instrumento(const QString& marca, double precio)
    : marca(marca), precio(precio) {}

QString Instrumento::getMarca() const {
    return marca;
}

double Instrumento::getPrecio() const {
    return precio;
}

void Instrumento::setMarca(const QString& marca) {
    this->marca = marca;
}

void Instrumento::setPrecio(double precio) {
    this->precio = precio;
}
