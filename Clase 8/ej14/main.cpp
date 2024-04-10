#include "login.h"
#include "form.h"
#include <QMessageBox>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    Formulario formulario;
    int attempts = 0;
    bool isBlocked = false;
    QDateTime lastFailedAttempt;
    const int MAX_ATTEMPTS = 3;
    const int BLOCK_DURATION = 5 * 60 * 1000; // 5 minutes in milliseconds

    // Timer to unblock user after BLOCK_DURATION
    QTimer unblockTimer;
    unblockTimer.setSingleShot(true);

    QObject::connect(&unblockTimer, &QTimer::timeout, [&isBlocked]()
                     {
                         isBlocked = false;
                     });

    QObject::connect(&login, &Login::callLogin, [&login, &formulario, &attempts, &isBlocked, &lastFailedAttempt, &unblockTimer](QString user, QString password)
                     {
                         if (isBlocked)
                         {
                             QMessageBox::warning(&login, "Inicio de sesión", "Usuario bloqueado. Intente nuevamente más tarde.");
                             return;
                         }

                         if (user == "admin" && password == "1111")
                         {
                             QMessageBox::information(&login, "Inicio de sesión", "Inicio de sesión exitoso.");
                             formulario.show();
                             login.hide();
                             attempts = 0; // Reset attempts on successful login
                             lastFailedAttempt = QDateTime(); // Reset lastFailedAttempt
                         }
                         else
                         {
                             attempts++;
                             if (attempts >= MAX_ATTEMPTS)
                             {
                                 isBlocked = true;
                                 lastFailedAttempt = QDateTime::currentDateTime();
                                 unblockTimer.start(BLOCK_DURATION);
                                 QMessageBox::warning(&login, "Inicio de sesión", "Bloqueado por 5 minutos.");
                             }
                             else
                             {
                                 QMessageBox::warning(&login, "Inicio de sesión", "Usuario o clave incorrectos.");
                             }
                             login.clearPassword();
                         }
                     });

    QObject::connect(&formulario, &Formulario::accepted, [&a]()
                     {
                         a.quit();
                     });

    login.show();

    return a.exec();
}
