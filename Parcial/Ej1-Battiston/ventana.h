#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();
    void setBienvenida(QString message);

private:
    Ui::Ventana *ui;
    QLabel *lMessage;
};

#endif // VENTANA_H
