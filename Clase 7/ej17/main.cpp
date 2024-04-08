#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

#include "login.h"
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    Window window;

    QObject::connect(&login, &Login::callLogin, [&login, &window](QString user, QString password)
    {
        if (user == "admin" && password == "1111") {
            QMessageBox::information(&login, "Inicio de sesión", "Inicio de sesión exitoso.");
            window.showMaximized();
            login.hide();
            } else {
            QMessageBox::warning(&login, "Inicio de sesión", "Usuario o clave incorrectos.");
            login.clearPassword();
            } });

    login.show();

    return a.exec();
}

