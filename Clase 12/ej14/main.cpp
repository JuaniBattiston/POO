#include "login.h"
#include "form.h"
#include "admindb.h"
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
    QTimer unblockTimer;
    unblockTimer.setSingleShot(true);

    qDebug() << QDir::currentPath();

    AdminDB adminDB;
    QSqlDatabase db = adminDB.getDB();
    bool valid_user = false;
    if (adminDB.conectar( "C:\\Users\\juani\\OneDrive\\Escritorio\\POO\\Clase 12\\db.sqlite" ) )
        qDebug() << "Conexion exitosa";
    else
        qDebug() << "Conexion NO exitosa";

    QObject::connect(&unblockTimer, &QTimer::timeout, [&isBlocked]()
                     {
                         isBlocked = false;
                     });

    QObject::connect(&login, &Login::callLogin, [&login, &formulario, &attempts, &isBlocked, &lastFailedAttempt, &unblockTimer, &db, &valid_user](QString user, QString password)
                     {
                         if (isBlocked)
                         {
                             QMessageBox::warning(&login, "Inicio de sesión", "Usuario bloqueado. Intente nuevamente más tarde.");
                             return;
                         }
                         if (true)  {
                             QSqlQuery* query = new QSqlQuery( db );
                             if (query->exec("SELECT nombre, apellido FROM usuarios WHERE usuario='" + user + "' AND clave='" + password + "'") && query->next()) {
                                 QSqlRecord record = query->record();

                                 // Obtenemos el número de la columna de los datos que necesitamos.
                                 int columnaNombre = record.indexOf("nombre");
                                 int columnaApellido = record.indexOf("apellido");
                                 valid_user = true;
                             } else {
                                 QMessageBox::warning(&login, "Inicio de sesión", "Usuario o clave incorrectos.");
                             }
                         }
                         if (valid_user)
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
