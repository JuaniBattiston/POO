#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QImage>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "boton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Ventana;
}
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void paintEvent(QPaintEvent *event);
    void slot_download_finished(QNetworkReply *reply);

private:
    Ui::Ventana *ui;
    QImage image;
    QNetworkAccessManager *manager;
};
#endif // VENTANA_H
