#ifndef LABELBUTTON_H
#define LABELBUTTON_H

#include <QWidget>
#include <QPainter>


namespace Ui {
class LabelButton;
}

class LabelButton : public QWidget
{
    Q_OBJECT

public:
    explicit LabelButton(QWidget *parent = nullptr);
    ~LabelButton();
    void setText(QString text);


private slots:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::LabelButton *ui;

signals:
    void signal_clic();
};


#endif // LABELBUTTON_H
