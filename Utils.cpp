#include <cmath>
#include "Utils.h"

using namespace std;

bool Utils::isPointInPlane(const Point& p, const Plane& plane) {
  return isEqualDouble(p.z_, -(plane.a_ * p.x_ + plane.b_ * p.y_ + plane.c_));
}

bool Utils::isEqualDouble(double x, double y) {
  return abs(x - y) < EPSILON;
}

bool Utils::isPointAbovePlane(const Point& point, const Plane& plane) {
  double projection_z = -(plane.a_ * point.x_ + plane.b_ * point.y_ + plane.c_);
  return point.z_ > projection_z;
}
