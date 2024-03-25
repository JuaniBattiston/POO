#ifndef LOGIN_H
#define LOGIN_H

#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


class Login : public QWidget {
    Q_OBJECT

private:
    QLineEdit *leUser;
    QLineEdit *lePassword;

public:
    Login(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *lUser = new QLabel("Usuario:");
        QLabel *lPassword = new QLabel("Clave:");

        leUser = new QLineEdit;
        lePassword = new QLineEdit;
        lePassword->setEchoMode(QLineEdit::Password);

        QPushButton *pbLogin = new QPushButton("Ingresar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lUser, 0, 0);
        layout->addWidget(lPassword, 1, 0);
        layout->addWidget(leUser, 0, 1);
        layout->addWidget(lePassword, 1, 1);
        layout->addWidget(pbLogin, 2, 1);

        setLayout(layout);

        connect(pbLogin, &QPushButton::clicked, this, &Login::onLogin);
        connect(lePassword, &QLineEdit::returnPressed, this, &Login::onLogin);
    }


    void clearPassword() {
        lePassword->clear();
    }

signals:
    void callLogin(QString user, QString password);

private slots:
    void onLogin() {
        QString user = leUser->text();
        QString password = lePassword->text();

        emit callLogin(user, password);
    }
};

#endif // LOGIN_H
