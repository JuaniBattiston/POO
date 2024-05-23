#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include "login.h"
#include "register.h"
#include "databaseviever.h"

namespace Ui {
class Manager;
}

class Manager : public QWidget
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    void slot_user_logged_in();
    void slot_register_user();
    void slot_register_to_login();

private:
    Ui::Manager *ui;
    Login *login;
    Register *register_user;
    DatabaseViever *database_viewer;
};

#endif // MANAGER_H
