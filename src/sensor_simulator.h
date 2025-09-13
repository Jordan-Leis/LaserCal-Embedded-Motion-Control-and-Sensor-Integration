#ifndef SENSOR_SIMULATOR_H
#define SENSOR_SIMULATOR_H

#include <deque>

class SensorSimulator {
public:
    explicit SensorSimulator(int windowSize = 5);
    double simulateReading(double trueValue);

private:
    int m_windowSize;
    std::deque<double> m_window;
};

#endif // SENSOR_SIMULATOR_H
