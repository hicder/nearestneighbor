#include <cmath>
#include "Utils.h"

using namespace std;

bool Utils::isPointInPlane(const Point& p, const Plane& plane) {
  return isEqualDouble(p.z_, -(plane.a * p.x_ + plane.b * p.y_ + plane.c));
}

bool Utils::isEqualDouble(double x, double y) {
  return abs(x - y) < EPSILON;
}
