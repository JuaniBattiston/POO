#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "widget.h"
#include <QtWidgets>
#include <QLayout>


class Barra : public QWidget {
    Q_OBJECT

private:
    float percentage = 0.0;

public:
    Barra(QWidget *parent = nullptr) : QWidget(parent) {

    }

    void paintEvent(QPaintEvent *) {
        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing);

        qreal rectWidth = width() - 10;
        qreal rectHeight = height() - height() * 0.4 - 10;
        qreal rectX = (width() - rectWidth) / 2;
        qreal rectY = (height() - rectHeight) / 2;
        QRectF rect = QRectF(rectX, rectY, rectWidth, rectHeight);
        p.setBrush(QBrush(Qt::white));
        p.setPen(QPen(QColor(Qt::blue), 2));
        p.drawRoundedRect(rect, 20, 20);

        qreal progressWidth = (rect.width() - 20) * percentage;
        qreal progressHeight = rect.height() * 0.6;
        qreal progressX = 15;
        qreal progressY = rect.center().y() - progressHeight / 2;

        QRectF progressBarRect = QRectF(progressX, progressY, progressWidth, progressHeight);
        p.setBrush(QColor(Qt::blue));
        p.setPen(Qt::NoPen);
        p.drawRoundedRect(progressBarRect, 10, 10);

        QString text = QString("%1%").arg(static_cast<int>(percentage * 100));
        p.setPen(Qt::blue);
        QRectF textRect = QRectF(0, height() - height() * 0.1, width() - width() * 0.1, -height() * 0.2); // Adjust the margin on the right
        p.drawText(textRect, Qt::AlignRight | Qt::AlignVCenter, text);
    }


    void setPercentage(float x) {
        percentage = x;
    }
};


#endif // PROGRESSBAR_H
