#include "admin.h"
#include "admindb.h"
#include <QApplication>

//Archivo main.cpp que instancia una aplicación Qt,
//crea un objeto Admin y se conecta a una base de
//datos utilizando la clase AdminDB.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //instancia admin
    Admin admin;
    //conexion a la base de datos
    bool has_connected = AdminDB::get_instance()->connect("../Ej2-Battiston/base_poo.sqlite");
    return a.exec();
}
