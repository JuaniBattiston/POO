#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>
#include <QSqlError>
#include <QCryptographicHash>

class AdminDB : public QObject  {
    Q_OBJECT

private:
    static AdminDB * instance;
    AdminDB();
    QSqlDatabase db;

public:
    static AdminDB * get_instance();

    bool connect(QString db_path);
    void close();
    QStringList validate_user( QString tabla, QString usuario, QString clave );
    QStringList register_user( QString tabla, QString name, QString family_name, QString usuario, QString clave );
    QVector<QStringList> select(QString query);
};


#endif // ADMINDB_H
