#include <chrono>
#include <climits>
#include <cmath>
#include <random>

#include "Utils.h"

using namespace std;

bool Utils::isPointInPlane(const Point& p, const Plane& plane) {
  return isEqualDouble(p.z_, plane.a_ * p.x_ + plane.b_ * p.y_ - plane.c_);
}

bool Utils::isEqualDouble(double x, double y) {
  return abs(x - y) < EPSILON;
}

bool Utils::isPointAbovePlane(const Point& point, const Plane& plane) {
  double projection_z = plane.a_ * point.x_ + plane.b_ * point.y_ - plane.c_;
  return point.z_ > projection_z;
}

shared_ptr<Plane> Utils::getLowestPlaneInSet(const PlaneSet& ps,
                                             double x,
                                             double y) {
  double minZ = INT_MAX;
  shared_ptr<Plane> lowestPlane = nullptr;
  for(const auto plane : ps) {
    double currZ = plane->calculateZ(x, y);
    if (currZ < minZ)  {
      lowestPlane = plane;
      minZ = currZ;
    }
  }
  return lowestPlane;
}

shared_ptr<Plane> Utils::getLowestPlaneAboveRay(const PlaneSet& planes,
                                                const VerticalRay& ray) {
  double minZ = INT_MAX;
  shared_ptr<Plane> lowestPlane = nullptr;
  for (const auto plane : planes) {
    double currZ = plane->calculateZ(ray.x_, ray.y_);
    if (currZ > ray.z_ && currZ < minZ) {
      lowestPlane = plane;
      minZ = currZ;
    }
  }

  return lowestPlane;
}

unsigned int Utils::getRandomNumber() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::minstd_rand0 generator (seed);
  return generator();
}
