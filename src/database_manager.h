#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QString>
#include <QVector>

class DatabaseManager {
public:
    bool open(const QString &path);
    void logMeasurement(double target, double measurement);
    QVector<double> fetchMeasurements() const;

private:
    QSqlDatabase m_db;
};

#endif // DATABASE_MANAGER_H
