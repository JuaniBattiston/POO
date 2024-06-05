#include "linea.h"

Linea::Linea(int x_inicial, int y_inicial, int x_final, int y_final)
    : x_inicial(x_inicial), y_inicial(y_inicial), x_final(x_final), y_final(y_final) {}

void Linea::set_x_inicial(const int x_inicial)
{
    this->x_inicial = x_inicial;
}

void Linea::set_y_inicial(const int y_inicial)
{
    this->y_inicial = y_inicial;
}

void Linea::set_x_final(const int x_final)
{
    this->x_final = x_final;
}

void Linea::set_y_final(const int y_final)
{
    this->y_final = y_final;
}

Linea::get_x_inicial() const
{
    return x_inicial;
}

Linea::get_y_inicial() const
{
    return y_inicial;
}

Linea::get_x_final() const
{
    return x_final;
}

Linea::get_y_final() const
{
    return y_final;
}

