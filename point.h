#ifndef POINT_H
#define POINT_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class Point
{
public:
    Point();
    Point(double x, double y);

    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);

    bool save();

private:
    double m_x;
    double m_y;
    QSqlDatabase m_database;
};

#endif // POINT_H
