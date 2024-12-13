#include "cviko1/robot.hpp"

void Robot::move(double dx, double dy) {
    x += dx;
    y += dy;
}

double Robot::getX() const {
    return x;
}

double Robot::getY() const {
    return y;
}
