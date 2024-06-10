#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo
{
public:
    Rectangulo(int x = 0, int y = 0, int ancho = 100, int alto = 100);
    void setX(const int x);
    void setY(const int y);
    void setAncho(const int ancho);
    void setAlto(const int alto);
    int getX() const;
    int getY() const;
    int getAncho() const;
    int getAlto() const;

private:
    int x;
    int y;
    int ancho;
    int alto;
};

#endif // RECTANGULO_H
