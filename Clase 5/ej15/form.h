#ifndef FORM_H
#define FORM_H

#include "widget.h"
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QGroupBox>
#include <QRandomGenerator>
#include <QMessageBox>


class Formulario : public QWidget {
    Q_OBJECT
public:
    Formulario(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *lFile = new QLabel("Legajo:");
        QLabel *lName = new QLabel("Nombre:");
        QLabel *lFamilyName = new QLabel("Apellido:");
        QLabel *lCaptcha = new QLabel("Captcha:");

        int randomNumber = QRandomGenerator::global()->bounded(1000, 10000);
        lCode = new QLabel();
        lCode->setText(QString::number(randomNumber));

        leFile = new QLineEdit;
        leName = new QLineEdit;
        leFamilyName = new QLineEdit;
        leCaptcha = new QLineEdit;

        QPushButton *pbAcceptForm = new QPushButton("Alta");

        QGroupBox *groupBox = new QGroupBox("Captcha");
        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(lCaptcha);
        vbox->addWidget(lCode);
        vbox->addWidget(leCaptcha);
        vbox->addWidget(pbAcceptForm);
        groupBox->setLayout(vbox);

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(lFile, 0, 0);
        layout->addWidget(lName, 1, 0);
        layout->addWidget(lFamilyName, 2, 0);
        layout->addWidget(leFile, 0, 1);
        layout->addWidget(leName, 1, 1);
        layout->addWidget(leFamilyName, 2, 1);
        layout->addWidget(groupBox, 4, 0);


        setLayout(layout);

        connect(pbAcceptForm, &QPushButton::clicked, this, &Formulario::onFormAccept);
    }

    QString getCaptchaCode() const {
        return lCode->text();
    }

    QString getCaptchaText() const {
        return leCaptcha->text();
    }

signals:
    void accepted();

private slots:
    void onFormAccept() {
        QString captchaCode = getCaptchaCode();
        QString captchaText = getCaptchaText();

        if (captchaCode == captchaText){
            emit accepted();
        } else {
            QMessageBox::warning(this, "Captcha Incorrecto", "Intentelo nuevamente.");
        }
    }

private:
    QLineEdit *leFile;
    QLineEdit *leName;
    QLineEdit *leFamilyName;
    QLineEdit *leCaptcha;
    QLabel *lCode;
};

#endif // FORM_H
