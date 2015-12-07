#pragma once
#include <memory>
#include <set>
#include <vector>
#include <cmath>

#include "Plane.h"
#include "Cutting.h"
/**
 * Represent a subset of plane
 */

class Subset {
 public:
  Subset();
  explicit Subset(const std::set<std::shared_ptr<Plane>>& planes);
  explicit Subset(std::shared_ptr<Plane> plane);

  void insertPlane(std::shared_ptr<Plane> plane);
  void construct();
  void deletePlane(std::shared_ptr<Plane>);

  std::shared_ptr<Subset> getDiff();
  bool isEmpty() const {
    return planeSet_.empty();
  }

  int depth() const {
    return std::floor(std::log2(liveSet_.size()));
  }
 public:
  /* S */
  std::set<std::shared_ptr<Plane>> planeSet_;

  /* List of S_i */
  std::vector<std::set<std::shared_ptr<Plane>>> setList_;

  /* S_live */
  std::set<std::shared_ptr<Plane>> liveSet_;

  /* S_static */
  std::set<std::shared_ptr<Plane>> staticSet_;

  /* T_i */
  std::vector<std::shared_ptr<Cutting>> cuttingList_;
};
