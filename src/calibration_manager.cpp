#include "calibration_manager.h"
#include <QtMath>

CalibrationManager::CalibrationManager(QObject *parent)
    : QObject(parent) {
    m_db.open("calibration.sqlite");
}

void CalibrationManager::runLinearTest() {
    Point start{0, 0};
    Point end{1, 1};
    auto path = m_motion.linearInterpolation(start, end, 20);
    for (const auto &p : path) {
        double measurement = m_sensor.simulateReading(qSqrt(p.x * p.x + p.y * p.y));
        m_db.logMeasurement(p.x, measurement);
    }
}

double CalibrationManager::averageMeasurement() const {
    auto values = m_db.fetchMeasurements();
    if (values.isEmpty())
        return 0.0;
    double sum = 0.0;
    for (double v : values)
        sum += v;
    return sum / values.size();
}
