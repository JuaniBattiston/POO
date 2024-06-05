#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>

class Instrumento {
public:
    Instrumento(const QString& marca, double precio);
    virtual ~Instrumento() = default;

    virtual void afinar() const = 0;

    // Getters and setters for common attributes
    QString getMarca() const;
    double getPrecio() const;
    void setMarca(const QString& marca);
    void setPrecio(double precio);

protected:
    QString marca;
    double precio;
};

#endif // INSTRUMENTO_H
