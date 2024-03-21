#include "widget.h"

#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel label;
    QPixmap pixmap("../image.jpg");

    pixmap = pixmap.scaled(a.screens()[0]->size(), Qt::KeepAspectRatio);
    label.setPixmap(pixmap);

    label.showMaximized();

    QTimer::singleShot(3000, [&a](){
        a.quit();
    });


    a.exec();
    return 0;
}
