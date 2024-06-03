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
    QString hashed_password = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();

    query->exec( "SELECT name, family_name FROM " +
                table + " WHERE username = '" + user +
                "' AND password = '" + hashed_password + "'" );

    while( query->next() )  {
        QSqlRecord sql_record = query->record();

        query_data << query->value( sql_record.indexOf( "name" ) ).toString();
        query_data << query->value( sql_record.indexOf( "family_name" ) ).toString();
    }

    return query_data;
}

QStringList AdminDB::register_user(QString table, QString name, QString family_name, QString user, QString password) {
    QStringList query_data;

    if (!db.isOpen())
        return query_data;

    QString hashed_password = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();

    QSqlQuery query(db);
    QString queryString = QString("INSERT INTO %1 (name, family_name, username, password) VALUES ('%2', '%3', '%4', '%5')")
                              .arg(table, name, family_name, user, hashed_password);

    if (query.exec(queryString)) {
        query_data << name << family_name << user;
    } else {
        qDebug() << "Error en register_user:" << query.lastError().text();
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

bool AdminDB::insert(QString query)
{
    QSqlQuery sql_query(query);
    return sql_query.exec();
}
