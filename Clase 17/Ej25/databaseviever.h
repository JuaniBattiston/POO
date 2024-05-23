#ifndef DATABASEVIEWER_H
#define DATABASEVIEWER_H

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>

namespace Ui {
class DatabaseViever;
}

class DatabaseViever : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseViever(QWidget *parent = nullptr);
    ~DatabaseViever();

    void loadUsers();

private slots:
    void onItemChanged(QTreeWidgetItem *item, int column);

private:
    Ui::DatabaseViever *ui;

    void setupTreeWidget();
};

#endif // DATABASEVIEWER_H
