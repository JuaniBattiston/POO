#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admindb.h"

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
    void slot_label_clicked();
    void slot_user_logged_in();

signals:
    void signal_user_logged_in();
    void signal_register_user();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
