#include "admindb.h"


AdminDB * AdminDB::instance = nullptr;

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB * AdminDB::get_instance()  {
    if( instance == nullptr )  {
        instance = new AdminDB;
    }
    return instance;
}

bool AdminDB::connect(QString db_path)  {
    qDebug() << "Conexión exitosa con la base de datos";
    db.setDatabaseName(db_path);

    if( db.open() )
        return true;

    return false;
}

void AdminDB::close()
{
    db.close();
}

QStringList AdminDB::validate_user(QString table, QString user, QString password)  {

    QStringList query_data;

    if ( ! db.isOpen() )
        return query_data;

    QSqlQuery *query = new QSqlQuery(db);

    query->exec( "SELECT username, password FROM " +
                table + " WHERE username = '" + user +
                "' AND password = '" + password + "'" );

    while( query->next() )  {
        QSqlRecord sql_record = query->record();

        query_data << query->value( sql_record.indexOf( "username" ) ).toString();
        query_data << query->value( sql_record.indexOf( "password" ) ).toString();
    }

    return query_data;
}


QVector<QStringList> AdminDB::select(QString query_str) {
    QVector<QStringList> results;

    QSqlQuery query(query_str);
    if (query.exec()) {
        while (query.next()) {
            QStringList sql_record;
            QSqlRecord record = query.record();
            int field_num = record.count();
            for (int i = 0; i < field_num; ++i) {
                sql_record.append(query.value(i).toString());
            }
            results.append(sql_record);
        }
    }

    return results;
}

