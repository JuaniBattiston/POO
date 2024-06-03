#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Manager;
}
QT_END_NAMESPACE

class Manager : public QWidget
{
    Q_OBJECT

public:
    Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void slot_handle_login();

private:
    Ui::Manager *ui;
    Login *login;
};
#endif // MANAGER_H
