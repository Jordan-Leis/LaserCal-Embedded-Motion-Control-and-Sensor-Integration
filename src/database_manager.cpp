#include "database_manager.h"
#include <QVariant>

bool DatabaseManager::open(const QString &path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if (!m_db.open()) {
        return false;
    }
    QSqlQuery q;
    q.exec("CREATE TABLE IF NOT EXISTS measurements (target REAL, measurement REAL)");
    return true;
}

void DatabaseManager::logMeasurement(double target, double measurement) {
    QSqlQuery q;
    q.prepare("INSERT INTO measurements (target, measurement) VALUES (?, ?)");
    q.addBindValue(target);
    q.addBindValue(measurement);
    q.exec();
}

QVector<double> DatabaseManager::fetchMeasurements() const {
    QVector<double> values;
    QSqlQuery q("SELECT measurement FROM measurements");
    while (q.next()) {
        values.append(q.value(0).toDouble());
    }
    return values;
}
