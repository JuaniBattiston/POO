#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
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

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::onFormAccept()
{
    QCoreApplication::quit();
}
