#ifndef CALIBRATION_MANAGER_H
#define CALIBRATION_MANAGER_H

#include "motion_controller.h"
#include "sensor_simulator.h"
#include "database_manager.h"

#include <QObject>

class CalibrationManager : public QObject {
    Q_OBJECT
public:
    explicit CalibrationManager(QObject *parent = nullptr);
    Q_INVOKABLE void runLinearTest();
    Q_INVOKABLE double averageMeasurement() const;

private:
    MotionController m_motion;
    SensorSimulator m_sensor;
    DatabaseManager m_db;
};

#endif // CALIBRATION_MANAGER_H
