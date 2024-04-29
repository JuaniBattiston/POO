#ifndef DESCARGADOR_H
#define DESCARGADOR_H

#include <QWidget>
#include <QLineEdit>
#include <QImage>
#include <QProgressBar>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class Descargador;
}
QT_END_NAMESPACE

class Descargador : public QWidget
{
    Q_OBJECT

public:
    Descargador(QWidget *parent = nullptr);
    ~Descargador();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_download_finished(QNetworkReply *reply);
    void slot_download_image();
    void slot_download_progress(qint64 bytesReceived, qint64 bytesTotal);

private:
    Ui::Descargador *ui;
    QLineEdit *leUrl;
    QImage image;
    QProgressBar *prbDownload;
    QPushButton *pbDownloadImage;
    QGridLayout *layout;
    QNetworkAccessManager *manager;
};
#endif // DESCARGADOR_H
