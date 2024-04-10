#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

#include "login.h"
#include "text.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    Text text;

    QObject::connect(&login, &Login::callLogin, [&login, &text, &a](QString user, QString password)
                     {
        if (user == "admin" && password == "1234") {
            login.hide();
            text.show();
        } else {
            QMessageBox::warning(&login, "Inicio de sesión", "Usuario o clave incorrectos.");
            login.clearPassword();
        } });

    login.show();

    return a.exec();
}
