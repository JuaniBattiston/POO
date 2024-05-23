#include "databaseviever.h"
#include "ui_databaseviever.h"
#include "admindb.h"

DatabaseViever::DatabaseViever(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DatabaseViever)
{
    ui->setupUi(this);
    setupTreeWidget();
    loadUsers();
    connect(ui->treeWidget, &QTreeWidget::itemChanged, this, &DatabaseViever::onItemChanged);
}


DatabaseViever::~DatabaseViever()
{
    delete ui;
}

void DatabaseViever::setupTreeWidget() {
    QStringList headers;
    headers << "ID" << "Name" << "Family Name" << "Username" << "Password";
    ui->treeWidget->setHeaderLabels(headers);
    ui->treeWidget->setColumnCount(headers.size());

    // Configurar el QTreeWidget para que los elementos sean editables
    ui->treeWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}

void DatabaseViever::loadUsers() {
    AdminDB* db = AdminDB::get_instance();

    QVector<QStringList> users = db->select("SELECT id, name, family_name, username, password FROM users");

    foreach (const QStringList &user, users) {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
        for (int i = 0; i < user.size(); ++i) {
            item->setText(i, user.at(i));
            item->setFlags(item->flags() | Qt::ItemIsEditable);  // Hacer que los elementos sean editables
        }
        ui->treeWidget->addTopLevelItem(item);
    }
}

void DatabaseViever::onItemChanged(QTreeWidgetItem *item, int column) {
    AdminDB* db = AdminDB::get_instance();

    int id = item->text(0).toInt();
    QString columnName;
    switch (column) {
    case 1: columnName = "name"; break;
    case 2: columnName = "family_name"; break;
    case 3: columnName = "username"; break;
    case 4: columnName = "password"; break;
    default: return;
    }

    QString queryStr = QString("UPDATE users SET %1 = '%2' WHERE id = %3")
                           .arg(columnName, item->text(column), QString::number(id));
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Error al actualizar la base de datos:" << query.lastError().text();
    }
}

