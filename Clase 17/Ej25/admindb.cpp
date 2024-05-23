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
    qDebug() << "La base se encuentra conectada...";
    db.setDatabaseName(db_path);

    if( db.open() )
        return true;

    return false;
}

QStringList AdminDB::validate_user( QString tabla, QString usuario, QString clave )  {

    QStringList datosPersonales;

    if ( ! db.isOpen() )
        return datosPersonales;

    QSqlQuery * query = new QSqlQuery( db );
    //QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
    //                                            QCryptographicHash::Md5 ).toHex();

    query->exec( "SELECT name, family_name FROM " +
                tabla + " WHERE username = '" + usuario +
                "' AND password = '" + clave + "'" );

    while( query->next() )  {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "name" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "family_name" ) ).toString();
    }

    return datosPersonales;
}

QStringList AdminDB::register_user(QString tabla, QString name, QString family_name, QString usuario, QString clave) {
    QStringList datosPersonales;

    if (!db.isOpen())
        return datosPersonales;

    QSqlQuery query(db);
    QString queryString = QString("INSERT INTO %1 (name, family_name, username, password) VALUES ('%2', '%3', '%4', '%5')")
                              .arg(tabla, name, family_name, usuario, clave);

    if (query.exec(queryString)) {
        datosPersonales << name << family_name << usuario;
    } else {
        qDebug() << "Error en register_user:" << query.lastError().text();
    }

    return datosPersonales;
}


QVector<QStringList> AdminDB::select(QString query_str) {
    QVector<QStringList> resultados;

    QSqlQuery query(query_str);
    if (query.exec()) {
        while (query.next()) {
            QStringList registro;
            QSqlRecord record = query.record();
            int fieldCount = record.count();
            for (int i = 0; i < fieldCount; ++i) {
                registro.append(query.value(i).toString());
            }
            resultados.append(registro);
        }
    }

    return resultados;
}

