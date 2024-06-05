#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include "instrumento.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Formulario;
}
QT_END_NAMESPACE

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void agregarInstrumento();
    void verStock();
    void actualizarFormulario(int index);

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> instrumentos;
};
#endif // FORMULARIO_H
