#pragma once

#include <utility>

class Plane {
  public:
    double a_;
    double b_;
    double c_;
    double d_;
    bool operator==(Plane const&) const;
    bool operator< (Plane const&) const;

    /* construct the plane z = ax + by - c given a 2d point */
    Plane(double, double);

    /* construct the plane z = ax + by - c, given a, b and c */
    Plane(double, double, double);

    /* convert the plane into the corresponding point in 2d space */
    std::pair<double, double> toPoint();

    double calculateZ(double x, double y);

    Plane& operator=(const Plane& other);
};

