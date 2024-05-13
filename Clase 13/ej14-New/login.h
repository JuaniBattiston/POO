#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPaintEvent>
#include <QJsonDocument>
#include <QSqlDatabase>
#include "admindb.h"
#include "formulario.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

private:
    Ui::Login *ui;
    QLineEdit *leUser;
    QLineEdit *lePassword;
    QPushButton *pbLogin;
    QLabel *lWeather;
    QCheckBox *cbHideTemp;
    QLabel *backgroundLabel;
    QLineEdit *leImageUrl;
    QPushButton *pbSetBackground;
    QNetworkAccessManager *managerimgs;
    QNetworkAccessManager *managerjson;
    QImage image;
    QSqlDatabase db;
    AdminDB adminDB;
    int login_atts;
    QTimer timer;
    const int BLOCK_DURATION = 5 * 60 * 1000;
    Formulario *formulario;

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void blockUser();
    void unblockUser();

protected:
    void paintEvent(QPaintEvent *);

signals:
    void signal_usuarioValidado( QString usuario );

private slots:
    void slot_validate_user();
    void slot_downloadFinished(QNetworkReply*);
    void slot_handle_temp_resp(QNetworkReply*);
    void slot_set_bg_img();
    void slot_toggleTempLabelVisibility(int state);

private:

};
#endif // LOGIN_H

