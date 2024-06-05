#include "principal.h"
#include "admindb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool _ = AdminDB::get_instance()->connect("..//lineas.db");
    Principal w;
    w.show();
    return a.exec();
}
