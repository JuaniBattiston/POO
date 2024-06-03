/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leUser;
    QLabel *label_2;
    QLineEdit *lePassword;
    QPushButton *pbLogin;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(Login);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leUser = new QLineEdit(Login);
        leUser->setObjectName("leUser");

        gridLayout->addWidget(leUser, 0, 1, 1, 1);

        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lePassword = new QLineEdit(Login);
        lePassword->setObjectName("lePassword");
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 1, 1, 1, 1);

        pbLogin = new QPushButton(Login);
        pbLogin->setObjectName("pbLogin");

        gridLayout->addWidget(pbLogin, 2, 1, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label->setText(QCoreApplication::translate("Login", "Usuario", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Contrase\303\261a", nullptr));
        pbLogin->setText(QCoreApplication::translate("Login", "Ingresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
