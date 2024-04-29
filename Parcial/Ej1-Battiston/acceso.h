#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QImage>
#include <QPainter>
#include "ventana.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Acceso;
}
QT_END_NAMESPACE

class Acceso : public QWidget
{
    Q_OBJECT

public:
    Acceso(QWidget *parent = nullptr);
    ~Acceso();

private slots:
    void slot_download_finished(QNetworkReply *reply);
    void slot_validate_user();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Acceso *ui;
    QImage image;
    QNetworkAccessManager *manager;
    int loginAttempts;
    Ventana *ventana;
};
#endif // ACCESO_H
