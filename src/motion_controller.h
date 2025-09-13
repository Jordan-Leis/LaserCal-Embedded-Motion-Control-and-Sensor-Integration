#ifndef MOTION_CONTROLLER_H
#define MOTION_CONTROLLER_H

#include <vector>

struct Point {
    double x;
    double y;
};

using Path = std::vector<Point>;

class MotionController {
public:
    Path linearInterpolation(const Point &start, const Point &end, int steps) const;
    Path circularInterpolation(const Point &center, double radius,
                               double startAngleDeg, double endAngleDeg, int steps) const;
};

#endif // MOTION_CONTROLLER_H
