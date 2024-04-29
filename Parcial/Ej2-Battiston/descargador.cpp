#include "descargador.h"
#include "ui_descargador.h"

Descargador::Descargador(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Descargador)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    leUrl = new QLineEdit;
    leUrl->setText("https://images.pexels.com/photos/417074/pexels-photo-417074.jpeg"); //corregido el link porque no funciona el otro
    leUrl->setReadOnly(true);
    prbDownload = new QProgressBar;
    pbDownloadImage = new QPushButton;
    pbDownloadImage->setText("Descargar");
    layout = new QGridLayout;

    layout->addWidget(leUrl, 0, 0);
    layout->addWidget(pbDownloadImage, 0, 1);
    layout->addWidget(prbDownload, 2, 0, 1, 2, Qt::AlignBottom);
    setLayout(layout);


    connect(pbDownloadImage, SIGNAL(pressed()), this, SLOT(slot_download_image()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_download_finished(QNetworkReply*)));
}

Descargador::~Descargador()
{
    delete ui;
}

void Descargador::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if(!image.isNull()){
        p.drawImage(0, 0, image.scaled(this->width(), this->height(), Qt::KeepAspectRatioByExpanding));
    }
}

void Descargador::slot_download_finished(QNetworkReply *reply)
{
    image = QImage::fromData(reply->readAll());
    repaint();
}

void Descargador::slot_download_image()
{
    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(leUrl->text())));
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(slot_download_progress(qint64, qint64)));
}

void Descargador::slot_download_progress(qint64 bytesReceived, qint64 bytesTotal)
{
    if (bytesTotal > 0) {
        prbDownload->setMaximum(bytesTotal);
        prbDownload->setValue(bytesReceived);
        prbDownload->update();
    }
}
