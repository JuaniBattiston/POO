#include "pintura.h"
#include "ui_pintura.h"

Pintura::Pintura(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    resize(400, 400);
    m_color = Qt::red;
    m_penSize = 5;
    m_image = QImage(size(), QImage::Format_ARGB32);
    m_image.fill(Qt::white);
}


void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_lastPoint = event->pos();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        drawLineTo(event->pos());
    }
}

void Pintura::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0, 0, m_image);
}

void Pintura::resizeEvent(QResizeEvent*) {
    m_image = QImage(size(), QImage::Format_ARGB32);
    m_image.fill(Qt::white);
}

void Pintura::wheelEvent(QWheelEvent *event) {
    m_penSize += event->angleDelta().y() / 120;
    m_penSize = qMax(1, m_penSize);
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_R) {
        m_color = Qt::red;
    } else if (event->key() == Qt::Key_G) {
        m_color = Qt::green;
    } else if (event->key() == Qt::Key_B) {
        m_color = Qt::blue;
    } else if (event->key() == Qt::Key_Escape) {
        clear();
    }
}

void Pintura::drawLineTo(const QPoint &endPoint) {
    QPainter painter(&m_image);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(m_color, m_penSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(m_lastPoint, endPoint);
    m_lastPoint = endPoint;
    update();
}

void Pintura::clear() {
    m_image.fill(Qt::white);
    update();
}
