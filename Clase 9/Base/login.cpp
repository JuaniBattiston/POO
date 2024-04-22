#include "login.h"
#include "ui_login.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QGridLayout>
#include <QLabel>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
    , manager(new QNetworkAccessManager(this))
    , index(0)
{
    ui->setupUi(this);
    get_all_ulrs_from_file();

    QVBoxLayout *layout = new QVBoxLayout(this);

    button_prev = new QPushButton("Anterior", this);
    button_next = new QPushButton("Siguiente", this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(button_prev);
    buttonLayout->addWidget(button_next);
    layout->addStretch(1);
    layout->addLayout(buttonLayout);

    setLayout(layout);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
    connect(button_next, SIGNAL(clicked()), this, SLOT(slot_next()));
    connect(button_prev, SIGNAL(clicked()), this, SLOT(slot_prev()));
}

login::~login()
{
    delete ui;
}

void login::get_all_ulrs_from_file()
{
    QFile file("text.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        manager->get(QNetworkRequest(QUrl(line)));
    }

    file.close();
}

void login::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if (!vec.empty()) {
        index = qBound(0, index, vec.size() - 1);
        p.drawImage(0, 0, vec.at(index).scaled(this->size()), Qt::KeepAspectRatio);
    }
}

void login::downloadFinished(QNetworkReply *reply)
{
    QImage downloaded_image = QImage::fromData(reply->readAll());
    vec.push_back(downloaded_image);
    if (vec.size() == 1) {
        repaint();
    }
}

void login::slot_next()
{
    index++;
    repaint();
}

void login::slot_prev()
{
    index--;
    repaint();
}

