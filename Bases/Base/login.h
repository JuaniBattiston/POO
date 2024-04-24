#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QPainter>
#include "ventana.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void slot_validate_user();
    void slot_download_finished(QNetworkReply* reply);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Login *ui;
    QLabel *lUsername;
    QLabel *lPassword;
    QLineEdit *leUsername;
    QLineEdit *lePassword;
    QPushButton *pbAuth;
    QNetworkAccessManager *manager;
    QImage image;
    Ventana *ventana;
};
#endif // LOGIN_H
