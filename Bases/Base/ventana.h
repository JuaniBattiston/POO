#ifndef VENTANA_H
#define VENTANA_H

#include <QDialog>
#include <QFile>
#include <QImage>
#include <QPainter>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Ventana;
}

class Ventana : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_add_user();

private:
    Ui::Ventana *ui;
    QImage image;
    QWidget *imageWidget;
    QLabel *ldni;
    QLabel *lName;
    QLabel *lFamilyName;
    QLineEdit *ledni;
    QLineEdit *leName;
    QLineEdit *leFamilyName;
    QPushButton *pbAddUser;
};

#endif // VENTANA_H
