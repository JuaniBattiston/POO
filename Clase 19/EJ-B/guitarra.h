#ifndef GUITARRA_H
#define GUITARRA_H

#include "Instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra(const QString& marca, double precio, int cantidadDeCuerdas);

    void afinar() const override;

    int getCantidadDeCuerdas() const;
    void setCantidadDeCuerdas(int cantidadDeCuerdas);

private:
    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
