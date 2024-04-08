#ifndef LOGIN_H
#define LOGIN_H

#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QApplication>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class Login : public QWidget
{
    Q_OBJECT

private:
    QLineEdit *leUser;
    QLineEdit *lePassword;
    QLabel *lWeather;
    QImage backgroundImage; // Change to QImage
    QLabel *backgroundLabel;

public:
    Login(QWidget *parent = nullptr) : QWidget(parent)
    {

        QLabel *lUser = new QLabel("Usuario:");
        QLabel *lPassword = new QLabel("Clave:");
        backgroundLabel = new QLabel;

        leUser = new QLineEdit;
        lePassword = new QLineEdit;
        lePassword->setEchoMode(QLineEdit::Password);

        QPushButton *pbLogin = new QPushButton("Ingresar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lUser, 0, 0);
        layout->addWidget(lPassword, 1, 0);
        layout->addWidget(leUser, 0, 1);
        layout->addWidget(lePassword, 1, 1);
        layout->addWidget(pbLogin, 2, 1);

        setLayout(layout);

        connect(pbLogin, &QPushButton::clicked, this, &Login::onLogin);
        connect(lePassword, &QLineEdit::returnPressed, this, &Login::onLogin);;

        downloadBackgroundImage("https://github.com/JuaniBattiston/terminal-config/assets/68969090/ce656567-02ec-40c9-8ff1-d59edd1d30a7"); // Replace with your default image URL

    }

    void clearPassword()
    {
        lePassword->clear();
    }

signals:
    void callLogin(QString user, QString password);

private slots:
    void onLogin()
    {
        QString user = leUser->text();
        QString password = lePassword->text();

        emit callLogin(user, password);
    }


    void downloadBackgroundImage(const QString &imageUrl)
    {
        QNetworkAccessManager *nam = new QNetworkAccessManager(this);
        connect(nam, &QNetworkAccessManager::finished, this, &Login::backgroundDownloadFinished);
        const QUrl url = QUrl(imageUrl);
        QNetworkRequest request(url);
        nam->get(request);
    }

    void resizeEvent(QResizeEvent* ){
        this->repaint();
        update();
    }

    void paintEvent(QPaintEvent*) {
        QPainter painter(this);
        painter.drawImage(0,0, backgroundImage); // Draw the background image
    }

    void backgroundDownloadFinished(QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray imageData = reply->readAll();
            QImage image;
            if (image.loadFromData(imageData)) {
                // Calculate the size to maintain aspect ratio and fill the widget
                QSize widgetSize = this->size();
                QSize scaledSize = image.size().scaled(widgetSize, Qt::KeepAspectRatioByExpanding);

                backgroundImage = image.scaled(scaledSize, Qt::KeepAspectRatioByExpanding); // Scale the image
                update(); // Trigger repaint to draw the new image
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

#endif // LOGIN_H

