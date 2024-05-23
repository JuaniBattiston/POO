#include "manager.h"
#include "admindb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool db = AdminDB::get_instance()->connect("C:\\Users\\juani\\OneDrive\\Escritorio\\POO\\users.db");

    Manager manager;
    return a.exec();
}
