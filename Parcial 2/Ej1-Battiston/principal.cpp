#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    this->setFixedSize(300, 300);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *)
{
    QVector<QStringList> data = AdminDB::get_instance()->select("SELECT x, y, ancho, alto FROM rectangulos");

    for (int i = 0; i < data.size(); i++)  {
        QStringList line = data.at(i);
        rectangulos.push_back(Rectangulo(line.at(0).toInt(), line.at(1).toInt(), line.at(2).toInt(), line.at(3).toInt()));
    }

    QPainter painter(this);
    for (int i = 0; i < rectangulos.size(); i++)  {
        Rectangulo rect = rectangulos.at(i);
        painter.drawRect(rect.getX(), rect.getY(), rect.getAncho(), rect.getAlto());
    }
}
