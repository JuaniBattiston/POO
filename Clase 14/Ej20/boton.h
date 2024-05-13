#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Boton;
}

class Boton : public QWidget
{
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = nullptr);
    ~Boton();
    // create color enum for the button
    enum Color {
        BLUE,
        RED,
        GREEN
    };

    // create a method to color the button in metro colors
    void colorear(Color color);
    void setText(QString text);

private slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Boton *ui;
    Color m_color;

signals:
    void signal_clic();
};

#endif // BOTON_H
