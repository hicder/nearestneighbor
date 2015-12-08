#pragma once
#include <memory>
#include <set>
#include <vector>
#include <cmath>

#include "Plane.h"
#include "Cutting.h"
#include "Utils.h"
/**
 * Represent a subset of plane
 */

class Subset {
 public:
  Subset();
  explicit Subset(const PlaneSet& planes);
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
  PlaneSet planeSet_;

  /* List of S_i */
  std::vector<PlaneSet> setList_;

  /* S_live */
  PlaneSet liveSet_;

  /* S_static */
  PlaneSet staticSet_;

  /* T_i */
  std::vector<std::shared_ptr<Cutting>> cuttingList_;
};
