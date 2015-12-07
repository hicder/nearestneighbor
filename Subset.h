#pragma once
#include <memory>
#include <set>

#include "Plane.h"

/**
 * Represent a subset of plane
 */
class Subset {
 public:
  Subset();
  explicit Subset(const std::set<std::shared_ptr<Plane>>& planes);
  void insertPlane(std::shared_ptr<Plane> plane);

  std::set<std::shared_ptr<Plane>> planeSet_;
};
