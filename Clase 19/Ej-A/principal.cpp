#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *)
{
    QVector<QStringList> data = AdminDB::get_instance()->select("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas;");
    qDebug() << data;
    QPainter painter(this);
    for (int i = 0; i < data.size(); i++)
    {
        Linea linea(data[i][0].toInt(), data[i][1].toInt(), data[i][2].toInt(), data[i][3].toInt());
        painter.drawLine(linea.get_x_inicial(), linea.get_y_inicial(), linea.get_x_final(), linea.get_y_final());
    }
}
