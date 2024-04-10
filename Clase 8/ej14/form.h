#ifndef FORM_H
#define FORM_H

#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


class Formulario : public QWidget {
    Q_OBJECT
public:
    Formulario(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *lFile = new QLabel("Legajo:");
        QLabel *lName = new QLabel("Nombre:");
        QLabel *lFamilyName = new QLabel("Apellido:");

        leFile = new QLineEdit;
        leName = new QLineEdit;
        leFamilyName = new QLineEdit;

        QPushButton *pbAcceptForm = new QPushButton("Aceptar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lFile, 0, 0);
        layout->addWidget(lName, 1, 0);
        layout->addWidget(lFamilyName, 2, 0);
        layout->addWidget(leFile, 0, 1);
        layout->addWidget(leName, 1, 1);
        layout->addWidget(leFamilyName, 2, 1);
        layout->addWidget(pbAcceptForm, 3, 1);

        setLayout(layout);

        connect(pbAcceptForm, &QPushButton::clicked, this, &Formulario::onFormAccept);
    }

signals:
    void accepted();

private slots:
    void onFormAccept() {
        emit accepted();
    }

private:
    QLineEdit *leFile;
    QLineEdit *leName;
    QLineEdit *leFamilyName;
};

#endif // FORM_H
