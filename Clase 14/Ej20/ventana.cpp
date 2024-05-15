#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    ui->widget->setText("Hola Mundo");
    ui->widget->colorear(Boton::Color::BLUE);
    ui->widget_2->setText("Hola Mundo 2");
    ui->widget_2->colorear(Boton::Color::RED);
    ui->widget_3->setText("Hola Mundo 3");
    ui->widget_3->colorear(Boton::Color::GREEN);
    ui->widget_4->setText("Hola Mundo 4");
    ui->widget_5->setText("Hola Mundo 5");

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_download_finished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("https://w0.peakpx.com/wallpaper/182/25/HD-wallpaper-low-poly-low-low-poly-paper-poly-wall.jpg")));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect = this->rect();
    painter.drawImage(rect, image);
}


void Ventana::slot_download_finished(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    repaint();
}
