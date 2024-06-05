#include "Viento.h"

Viento::Viento(const QString& marca, double precio, const QString& metalUsado)
    : Instrumento(marca, precio), metal_usado(metalUsado) {}

void Viento::afinar() const {
    qDebug() << "Afinando viento";
}

QString Viento::getMetalUsado() const {
    return metal_usado;
}

void Viento::setMetalUsado(const QString& metalUsado) {
    this->metal_usado = metalUsado;
}
