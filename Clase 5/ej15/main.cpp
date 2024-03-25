#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

#include "login.h"
#include "form.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login login;
    Formulario formulario;

    QObject::connect(&login, &Login::callLogin, [&login, &formulario](QString user, QString password) {
        if (user == "admin" && password == "1111") {
            QMessageBox::information(&login, "Inicio de sesión", "Inicio de sesión exitoso.");
            formulario.show();
            login.hide();
        } else {
            QMessageBox::warning(&login, "Inicio de sesión", "Usuario o clave incorrectos.");
            login.clearPassword();
        }
    });

    QObject::connect(&formulario, &Formulario::accepted, [&a]() {
        a.quit();
    });

    login.show();

    return a.exec();
}
