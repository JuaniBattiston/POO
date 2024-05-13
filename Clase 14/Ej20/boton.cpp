#include "boton.h"
#include "ui_boton.h"

Boton::Boton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Boton)
    , m_color(GREEN)
{
    ui->setupUi(this);
}

Boton::~Boton()
{
    delete ui;
}

void Boton::colorear(Color color)
{
    m_color = color;
    update();
}

void Boton::setText(QString text)
{
    ui->label->setText(text);
}


void Boton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect = this->rect();
    painter.fillRect(rect, m_color ==Color::BLUE ? Qt::blue : m_color == Color::GREEN ? Qt::green : Qt::red);
}

void Boton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Click en el boton";
    emit signal_clic();
}
