#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();
    void downloadFile(const QString &urlString);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void replyFinished(QNetworkReply *reply);
    void slot_pbUrl_clicked();
    void slot_selectDirectory_clicked();
    void slot_selectImage_clicked();

private:
    Ui::Window *ui;
    QNetworkAccessManager manager;
    QString downloadDirectory;
    QImage image;
};

#endif // WINDOW_H

