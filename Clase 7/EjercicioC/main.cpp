#include "widget.h"

#include <QApplication>
#include <QGridLayout>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "progressbar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    Barra barra;
    barra.setFixedHeight(80);
    QLineEdit qle;
    QPushButton pb("Descargar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&qle, 1, 0);
    layout->addWidget(&pb, 2, 0);
    layout->addWidget(&barra, 3, 0);

    w.setLayout(layout);
    w.show();

    QNetworkAccessManager manager;

    QObject::connect(&pb, &QPushButton::clicked, [&](){
        QUrl url(qle.text());

        if (!url.isValid()) {
            qDebug() << "URL no válida";
            return;
        }

        QNetworkReply *reply = manager.get(QNetworkRequest(url));

        QObject::connect(reply, &QNetworkReply::downloadProgress, [&barra](qint64 bytesReceived, qint64 bytesTotal){
            if (bytesTotal > 0) {
                qreal percentage = (qreal)bytesReceived / bytesTotal;
                barra.setPercentage(percentage);
                barra.update();
            }
        });

        QObject::connect(reply, &QNetworkReply::finished, [&](){
            qDebug() << "Descarga completada";
            reply->deleteLater();
        });
    });

    return a.exec();
}
