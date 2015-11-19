#pragma once

#include <utility>

class Plane {
  public:
    double a;
    double b;
    double c;
    bool operator==(Plane const&) const;
    bool operator< (Plane const&) const;
    Plane(double, double); // construct the plane -z = ax + by + c given a 2d point
    Plane(double, double, double); // construct the plane -z = ax + by + c, given a, b and c
    std::pair<double, double> toPoint(); // convert the plane into the corresponding point in 2d space
};

