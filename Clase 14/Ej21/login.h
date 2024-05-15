#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "ventana.h"
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
    void slot_validate_user();

private:
    Ui::Login *ui;
    Ventana *window;
    QSqlDatabase db;
    AdminDB adminDB;
};
#endif // LOGIN_H
