#ifndef TECLADO_H
#define TECLADO_H

#include "Instrumento.h"

class Teclado : public Instrumento {
public:
    Teclado(const QString& marca, double precio, int cantidadDeTeclas);

    void afinar() const override;

    // Getters and setters for specific attributes
    int getCantidadDeTeclas() const;
    void setCantidadDeTeclas(int cantidadDeTeclas);

private:
    int cantidad_de_teclas;
};

#endif // TECLADO_H
