#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admindb.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void slot_login();

signals:
    void signal_login();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
