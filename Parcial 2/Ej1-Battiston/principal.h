#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include "rectangulo.h"
#include "admindb.h"
#include <QPainter>

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
    QVector<Rectangulo> rectangulos;
};
#endif // PRINCIPAL_H
