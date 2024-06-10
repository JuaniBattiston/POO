#include "rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int ancho, int alto)
    : x(x), y(y), ancho(ancho), alto(alto)
{
}

void Rectangulo::setX(const int x)
{
    this->x = x;
}

void Rectangulo::setY(const int y)
{
    this->y = y;
}

void Rectangulo::setAncho(const int ancho)
{
    this->ancho = ancho;
}

void Rectangulo::setAlto(const int alto)
{
    this->alto = alto;
}

int Rectangulo::getX() const
{
    return x;
}

int Rectangulo::getY() const
{
    return y;
}

int Rectangulo::getAncho() const
{
    return ancho;
}

int Rectangulo::getAlto() const
{
    return alto;
}
