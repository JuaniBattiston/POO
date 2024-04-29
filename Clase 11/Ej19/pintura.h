#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

class Pintura : public QWidget {
    Q_OBJECT

public:
    explicit Pintura(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);
    void clear();

    QImage m_image;
    QPoint m_lastPoint;
    QColor m_color;
    int m_penSize;
};

#endif // PINTURA_H
