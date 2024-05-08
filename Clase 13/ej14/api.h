#ifndef API_H
#define API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class ApiConnection : public QObject
{
    Q_OBJECT
public:
    explicit ApiConnection(QObject *parent = nullptr) : QObject(parent) {}

    void openConnection(const QUrl &url) {
        QNetworkRequest request(url);
        QNetworkReply *reply = m_manager.get(request);

        connect(reply, &QNetworkReply::finished, this, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                processResponse(responseData);
            } else {
                qDebug() << "Connection error:" << reply->errorString();
            }

            reply->deleteLater();
        });
    }

signals:
    void apiResponseReceived(double temperature);

private:
    QNetworkAccessManager m_manager;

    void processResponse(const QByteArray &response) {
        QJsonParseError parseError;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(response, &parseError);

        if (parseError.error != QJsonParseError::NoError) {
            qDebug() << "JSON parse error:" << parseError.errorString();
            return;
        }

        if (!jsonResponse.isObject()) {
            qDebug() << "JSON response is not an object.";
            return;
        }

        QJsonObject jsonObject = jsonResponse.object();
        if (jsonObject.contains("current")) {
            QJsonObject currentObject = jsonObject["current"].toObject();
            if (currentObject.contains("temp_c")) {
                QJsonValue tempValue = currentObject["temp_c"];
                if (tempValue.isDouble()) {
                    double temperature = tempValue.toDouble();
                    emit apiResponseReceived(temperature);
                } else {
                    qDebug() << "Temperature value is not a double.";
                }
            } else {
                qDebug() << "No 'temp_c' field in 'current' object.";
            }
        } else {
            qDebug() << "No 'current' object in JSON response.";
        }
    }
};

#endif // API_H

