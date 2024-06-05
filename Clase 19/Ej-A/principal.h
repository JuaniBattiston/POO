#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QPainter>
#include "admindb.h"
#include "linea.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Principal;
}
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
