#pragma once

class Robot {
public:
    Robot() : x(0.0), y(0.0) {}
    void move(double dx, double dy);
    double getX() const;
    double getY() const;

private:
    double x, y;
};

