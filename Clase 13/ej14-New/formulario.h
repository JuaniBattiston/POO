#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QGridLayout>

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void onFormAccept();

private:
    Ui::Formulario *ui;
    QLineEdit *leFile;
    QLineEdit *leName;
    QLineEdit *leFamilyName;
};

#endif // FORMULARIO_H
