#include "acceso.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Acceso w;
    w.hide();
    return a.exec();
}
