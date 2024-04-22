#include "window.h"
#include "ui_window.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);

    get_all_ulrs_from_file();
}

Window::~Window()
{
    delete ui;
}

void Window::get_all_ulrs_from_file()
{
    QFile file("text.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
    }

    file.close();
}
