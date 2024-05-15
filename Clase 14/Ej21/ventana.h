#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPushButton>

class Login;

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();
    void set_login(Login *login);

private slots:
    void slot_go_back();


private:
    Ui::Ventana *ui;
    QPushButton *pbGoBack;
    Login *login;
};

#endif // VENTANA_H
