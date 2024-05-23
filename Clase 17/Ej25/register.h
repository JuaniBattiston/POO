#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "admindb.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void slot_register_user();

signals:
    void signal_user_registered();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
