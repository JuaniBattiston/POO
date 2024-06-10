#include "principal.h"
#include "admindb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal w;
    bool _ = AdminDB::get_instance()->connect("..//Ej1-Battiston//rectangles.sqlite");
    w.show();
    return a.exec();
}
