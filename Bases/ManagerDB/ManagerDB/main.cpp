#include "manager.h"
#include "admindb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool _ = AdminDB::get_instance()->connect("..//..//..//users.db");
    Manager w;
    return a.exec();
}
