#pragma once
#include <set>

#include "Point.h"
#include "Plane.h"

class Utils {
 public:
  static constexpr double EPSILON = 0.0000000001;
  static bool isPointInPlane(const Point& p, const Plane& plane);
  static bool isEqualDouble(double x, double y);
  static bool isPointAbovePlane(const Point& point, const Plane& plane);
}; // Utils

struct PlaneComparator {
  bool operator() (const std::shared_ptr<Plane>& lhs,
                   const std::shared_ptr<Plane>& rhs) const {
    return *lhs < *rhs;
  }
};

typedef std::set<std::shared_ptr<Plane>, PlaneComparator> PlaneSet;
