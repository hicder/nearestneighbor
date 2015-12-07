#pragma once
#include "Point.h"
#include "Plane.h"

class Utils {
 public:
  static constexpr double EPSILON = 0.0000000001;
  static bool isPointInPlane(const Point& p, const Plane& plane);
  static bool isEqualDouble(double x, double y);
}; // Utils
