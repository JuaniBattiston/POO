#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

    void get_all_ulrs_from_file();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void downloadFinished(QNetworkReply* reply);
    void slot_next();
    void slot_prev();

private:
    Ui::login *ui;
    QImage image;
    QNetworkAccessManager *manager;
    QPushButton *button_prev;
    QPushButton *button_next;
    QLabel *img;
    int index;
    QVector<QImage> vec;

};

#endif // LOGIN_H
