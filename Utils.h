#pragma once
#include <set>

#include "Plane.h"
#include "Point.h"
#include "VerticalRay.h"

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

  /* Two double number within this is considered equal. */
  static constexpr double EPSILON = 0.0000000001;

  /* Check if point is on the plane. */
  static bool isPointInPlane(const Point& p, const Plane& plane);

  /* Function to compare 2 double number, due to computer rounding errors. */
  static bool isEqualDouble(double x, double y);

  /* Check if point is above a plane. */
  static bool isPointAbovePlane(const Point& point, const Plane& plane);

  /* Get lowest plane at an (x,y) coordinate. */
  static std::shared_ptr<Plane> getLowestPlaneInSet(const PlaneSet& ps,
                                                    double x,
                                                    double y);

  /* Get lowest plane above a vertical ray.*/
  static std::shared_ptr<Plane> getLowestPlaneAboveRay(const PlaneSet& ps,
                                                       const VerticalRay& ray);

  /* Get an integer random number. */
  static unsigned int getRandomNumber();
}; // Utils

