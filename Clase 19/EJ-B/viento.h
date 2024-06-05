#ifndef VIENTO_H
#define VIENTO_H

#include "Instrumento.h"

class Viento : public Instrumento {
public:
    Viento(const QString& marca, double precio, const QString& metalUsado);

    void afinar() const override;

    // Getters and setters for specific attributes
    QString getMetalUsado() const;
    void setMetalUsado(const QString& metalUsado);

private:
    QString metal_usado;
};

#endif // VIENTO_H
