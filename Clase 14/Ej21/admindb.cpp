#include "admindb.h"
#include "ui_admindb.h"

AdminDB::AdminDB()  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}


QSqlDatabase AdminDB::getDB()  {
    return db;
}


QStringList AdminDB::validarUsuario( QString tabla, QString usuario, QString clave )  {

    QStringList datosPersonales;

    if ( ! db.isOpen() )
        return datosPersonales;

    QSqlQuery * query = new QSqlQuery( db );
    //QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
    //                                            QCryptographicHash::Md5 ).toHex();

    query->exec( "SELECT nombre, apellido FROM " +
                tabla + " WHERE usuario = '" + usuario +
                "' AND clave = '" + clave + "'" );

    while( query->next() )  {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
    }

    return datosPersonales;
}


QVector<QStringList> AdminDB::select(QString comando) {
    QVector<QStringList> resultados;

    QSqlQuery query(comando);
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
