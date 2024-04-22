#include "window.h"
#include "ui_window.h"
#include <QPainter>

Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
    , manager (new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));

    QString url_string = "https://img.freepik.com/foto-gratis/papel-pintado-gatito-lindo-fantasia_1409-6188.jpg";
    manager->get(QNetworkRequest(QUrl(url_string)));
}

Window::~Window()
{
    delete ui;
}

void Window::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if (!image.isNull()) {
        p.drawImage(0, 0, image.scaled(this->width(), this->height()));
    }
}

void Window::downloadFinished(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    this->repaint();
}

