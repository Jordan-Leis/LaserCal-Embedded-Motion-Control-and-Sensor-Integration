#include "sensor_simulator.h"
#include <random>

SensorSimulator::SensorSimulator(int windowSize) : m_windowSize(windowSize) {}

double SensorSimulator::simulateReading(double trueValue) {
    static std::default_random_engine eng{std::random_device{}()};
    std::normal_distribution<double> dist(0.0, 0.05);
    double noisy = trueValue + dist(eng);
    m_window.push_back(noisy);
    if (m_window.size() > static_cast<size_t>(m_windowSize)) {
        m_window.pop_front();
    }
    double sum = 0.0;
    for (double v : m_window) {
        sum += v;
    }
    return sum / m_window.size();
}
