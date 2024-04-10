#ifndef TEXT_H
#define TEXT_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Text : public QWidget
{
    Q_OBJECT

private:
    QTextEdit *qedit;
    QLineEdit *urlLineEdit;
    QNetworkAccessManager *networkManager;

public:
    Text(QWidget *parent = nullptr) : QWidget(parent)
    {
        QHBoxLayout *layout = new QHBoxLayout(this);

        qedit = new QTextEdit(this);
        layout->addWidget(qedit);

        urlLineEdit = new QLineEdit(this);
        layout->addWidget(urlLineEdit);

        connect(urlLineEdit, &QLineEdit::returnPressed, this, &Text::fetchUrlHtml);

        networkManager = new QNetworkAccessManager(this);
        connect(networkManager, &QNetworkAccessManager::finished, this, &Text::onNetworkReply);
    }

signals:

private slots:
    void fetchUrlHtml()
    {
        QString urlString = urlLineEdit->text();
        QUrl url(urlString);
        QNetworkRequest request(url);
        networkManager->get(request);
    }

    void onNetworkReply(QNetworkReply *reply)
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray data = reply->readAll();
            QString html = QString::fromUtf8(data);
            qedit->setHtml(html);
        }
        else
        {
            qedit->clear();
            qedit->setPlainText("Error al cargar la URL: " + reply->errorString());
        }
        reply->deleteLater();
    }
};

#endif // TEXT_H
