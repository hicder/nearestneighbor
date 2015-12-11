#pragma once
#include <set>

#include "Point.h"
#include "Plane.h"

#define C 1
#define C_PRIME 1
#define C_DOUBLE_PRIME 5

struct PlaneComparator {
  bool operator() (const std::shared_ptr<Plane>& lhs,
                   const std::shared_ptr<Plane>& rhs) const {
    return *lhs < *rhs;
  }
};

typedef std::set<std::shared_ptr<Plane>, PlaneComparator> PlaneSet;

class Utils {
 public:
  static constexpr double EPSILON = 0.0000000001;
  static bool isPointInPlane(const Point& p, const Plane& plane);
  static bool isEqualDouble(double x, double y);
  static bool isPointAbovePlane(const Point& point, const Plane& plane);
  static std::shared_ptr<Plane> getLowestPlaneInSet(PlaneSet ps, double x, double y);
}; // Utils

