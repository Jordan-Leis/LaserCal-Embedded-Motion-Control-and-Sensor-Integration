#include "motion_controller.h"
#include <cmath>

Path MotionController::linearInterpolation(const Point &start, const Point &end, int steps) const {
    Path path;
    if (steps <= 1) {
        path.push_back(start);
        path.push_back(end);
        return path;
    }
    for (int i = 0; i <= steps; ++i) {
        double t = static_cast<double>(i) / steps;
        Point p{start.x + t * (end.x - start.x),
                start.y + t * (end.y - start.y)};
        path.push_back(p);
    }
    return path;
}

Path MotionController::circularInterpolation(const Point &center, double radius,
                                              double startAngleDeg, double endAngleDeg, int steps) const {
    Path path;
    double startRad = startAngleDeg * M_PI / 180.0;
    double endRad = endAngleDeg * M_PI / 180.0;
    for (int i = 0; i <= steps; ++i) {
        double t = static_cast<double>(i) / steps;
        double angle = startRad + t * (endRad - startRad);
        Point p{center.x + radius * std::cos(angle),
                center.y + radius * std::sin(angle)};
        path.push_back(p);
    }
    return path;
}
