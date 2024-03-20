#include "widget.h"

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel hi("<H2 aling=right> Hola </H2>");
    hi.show();

    QWidget window;
    window.show();

    QPushButton button("Hola");
    button.show();

    QLineEdit lineEdit("Vacio");
    lineEdit.show();

    app.exec();
    return 0;
}
