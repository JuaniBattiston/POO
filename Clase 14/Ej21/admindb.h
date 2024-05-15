#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>

class AdminDB : public QObject  {
    Q_OBJECT

public:
    AdminDB();
    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();
    QStringList validarUsuario( QString tabla, QString usuario, QString clave );
    QVector<QStringList> select(QString comando);

private:
    QSqlDatabase db;
};


#endif // ADMINDB_H
