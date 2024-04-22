#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class Window;
}
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private:
    QImage image;
    QNetworkAccessManager *manager;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void downloadFinished(QNetworkReply* reply);

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
