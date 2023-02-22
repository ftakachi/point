#include "Point.h"

Point::Point() :
    m_x(0),
    m_y(0)
{
    m_database = QSqlDatabase::addDatabase("QMYSQL");
    m_database.setHostName("localhost");
    m_database.setDatabaseName("nom_de_la_base_de_donnees");
    m_database.setUserName("nom_utilisateur");
    m_database.setPassword("mot_de_passe");
}

Point::Point(double x, double y) :
    m_x(x),
    m_y(y)
{
    m_database = QSqlDatabase::addDatabase("QMYSQL");
    m_database.setHostName("localhost");
    m_database.setDatabaseName("nom_de_la_base_de_donnees");
    m_database.setUserName("root");
    m_database.setPassword("root");
}

double Point::getX() const
{
    return m_x;
}

void Point::setX(double x)
{
    m_x = x;
}

double Point::getY() const
{
    return m_y;
}

void Point::setY(double y)
{
    m_y = y;
}

bool Point::save()
{
    bool success = true;
    m_database.open();
    if (!m_database.isOpen()) {
        success = false;
    } else {
        QSqlQuery query;
        query.prepare("INSERT INTO points (x, y) VALUES (:x, :y)");
        query.bindValue(":x", QVariant(m_x));
        query.bindValue(":y", QVariant(m_y));
        if (!query.exec()) {
            success = false;
            qDebug() << "Erreur d'insertion dans la base de données :" << query.lastError();
        }
        m_database.close();
    }
    return success;
}
