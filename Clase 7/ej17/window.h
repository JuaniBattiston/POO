#ifndef WINDOW_H
#define WINDOW_H

#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QImage>
#include <QSlider>
#include <QSpinBox>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class Window : public QWidget
{
    Q_OBJECT

private:
    QImage backgroundImage; // Change to QImage

public:
    Window(QWidget *parent = nullptr) : QWidget(parent)
    {
        // Connect the resizeSignal to the updateBackgroundImage slot
        connect(this, &Window::resized, this, &Window::updateBackgroundImage);

        downloadBackgroundImage("https://github.com/JuaniBattiston/terminal-config/assets/68969090/ce656567-02ec-40c9-8ff1-d59edd1d30a7"); // Replace with your default image URL
    }
signals:
    void resized(QResizeEvent *event); // Define a signal to pass resize events to the slot

private slots:
    void updateBackgroundImage(QResizeEvent *event)
    {
        QSize widgetSize = event->size();
        QSize scaledSize = backgroundImage.size().scaled(widgetSize, Qt::KeepAspectRatioByExpanding);
        backgroundImage = backgroundImage.scaled(scaledSize, Qt::KeepAspectRatioByExpanding);
        update();
    }

    void paintEvent(QPaintEvent*) {
        QPainter painter(this);
        painter.drawImage(0,0, backgroundImage); // Draw the background image
    }

    void downloadBackgroundImage(const QString &imageUrl)
    {
        QNetworkAccessManager *nam = new QNetworkAccessManager(this);
        connect(nam, &QNetworkAccessManager::finished, this, &Window::backgroundDownloadFinished);
        const QUrl url = QUrl(imageUrl);
        QNetworkRequest request(url);
        nam->get(request);
    }

    void backgroundDownloadFinished(QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray imageData = reply->readAll();
            QImage image;
            if (image.loadFromData(imageData)) {
                QSize widgetSize = this->size();
                QSize scaledSize = image.size().scaled(widgetSize, Qt::KeepAspectRatioByExpanding);

                backgroundImage = image.scaled(scaledSize, Qt::KeepAspectRatioByExpanding);
                update();
            } else {
                qDebug() << "Error loading background image from data";
            }
        }
        else
        {
            qDebug() << "Error downloading background image:" << reply->errorString();
        }

        reply->deleteLater();
    }
};

#endif //WINDOW_H

