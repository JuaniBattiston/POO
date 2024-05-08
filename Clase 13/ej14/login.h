#ifndef LOGIN_H
#define LOGIN_H

#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "api.h"

class Login : public QWidget
{
    Q_OBJECT

private:
    QLineEdit *leUser;
    QLineEdit *lePassword;
    ApiConnection manager;
    QLabel *lWeather;
    QCheckBox *cbHideTemp;
    QLabel *backgroundLabel; // Added QLabel for background image
    QLineEdit *leImageUrl; // Added QLineEdit for image URL input
    QPushButton *pbSetBackground; // Added QPushButton to trigger background setting

public:
    Login(QWidget *parent = nullptr) : QWidget(parent)
    {

        QLabel *lUser = new QLabel("Usuario:");
        QLabel *lPassword = new QLabel("Clave:");
        lWeather = new QLabel("Weather Info");
        cbHideTemp = new QCheckBox("Hide Temp");
        backgroundLabel = new QLabel; // Initialize background QLabel

        leUser = new QLineEdit;
        lePassword = new QLineEdit;
        lePassword->setEchoMode(QLineEdit::Password);

        QPushButton *pbLogin = new QPushButton("Ingresar");

        leImageUrl = new QLineEdit; // Initialize QLineEdit for image URL input
        pbSetBackground = new QPushButton("Set Background"); // Initialize QPushButton to trigger background setting

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lUser, 0, 0);
        layout->addWidget(lPassword, 1, 0);
        layout->addWidget(leUser, 0, 1);
        layout->addWidget(lePassword, 1, 1);
        layout->addWidget(pbLogin, 2, 1);
        layout->addWidget(lWeather, 3, 1);
        layout->addWidget(cbHideTemp, 4, 1);

        // Add QLineEdit and QPushButton to the layout
        layout->addWidget(leImageUrl, 5, 0, 1, 2);
        layout->addWidget(pbSetBackground, 6, 0, 1, 2);

        setLayout(layout);

        connect(pbLogin, &QPushButton::clicked, this, &Login::onLogin);
        connect(lePassword, &QLineEdit::returnPressed, this, &Login::onLogin);

        connect(&manager, &ApiConnection::apiResponseReceived, this, &Login::handleTemperature);
        manager.openConnection(QUrl("https://api.weatherapi.com/v1/current.json?key=e59137c754614dfebf9224202240304&q=-31.4135%20-64.18105"));
        connect(cbHideTemp, &QCheckBox::stateChanged, this, &Login::toggleTempLabelVisibility);

        downloadBackgroundImage("https://raw.githubusercontent.com/JuaniBattiston/Proyecto-LAB2/main/img/cancha3.jpg?token=GHSAT0AAAAAACPALTNWR2QC6CK5XWYJSJ4YZQUMGKA"); // Replace with your default image URL

        // Connect the QPushButton to trigger background setting
        connect(pbSetBackground, &QPushButton::clicked, this, &Login::setBackgroundFromUrl);
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

    void handleTemperature(double temperature)
    {
        QString responseString = QString::number(temperature);
        QString temp = "Temperatura: ";
        lWeather->setText(temp + responseString);
    }

    // Slot to toggle visibility of temperature label
    void toggleTempLabelVisibility(int state)
    {
        if (state == Qt::Checked)
        {
            lWeather->hide();
        }
        else
        {
            lWeather->show();
        }
    }

    // Function to download background image
    void downloadBackgroundImage(const QString &imageUrl)
    {
        QNetworkAccessManager *nam = new QNetworkAccessManager(this);
        connect(nam, &QNetworkAccessManager::finished, this, &Login::backgroundDownloadFinished);
        const QUrl url = QUrl(imageUrl);
        QNetworkRequest request(url);
        nam->get(request);
    }

    // Slot to handle background image download finished
    void backgroundDownloadFinished(QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QPixmap backgroundPixmap;
            backgroundPixmap.loadFromData(reply->readAll());

            // Calculate the scaled pixmap size to maintain aspect ratio
            QSize scaledSize = size();
            scaledSize.scale(size(), Qt::KeepAspectRatio);

            // Scale the pixmap to fit the scaled size while preserving aspect ratio
            backgroundPixmap = backgroundPixmap.scaled(scaledSize, Qt::KeepAspectRatioByExpanding);

            // Create a palette with the background pixmap
            QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(backgroundPixmap));

            // Set the palette to the widget
            this->setPalette(palette);
            this->setAutoFillBackground(true);
        }
        else
        {
            qDebug() << "Error downloading background image:" << reply->errorString();
        }

        reply->deleteLater();
    }

    // Slot to set background from entered URL
    void setBackgroundFromUrl()
    {
        QString imageUrl = leImageUrl->text();
        downloadBackgroundImage(imageUrl);
    }
};

#endif // LOGIN_H
