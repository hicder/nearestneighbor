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
  PlaneSet deletePlane(std::shared_ptr<Plane>);

  /* Return S - S_live */
  std::shared_ptr<Subset> getDiff();

  bool isEmpty() const {
    return planeSet_.empty();
  }

  int depth() const {
    return std::floor(std::log2(liveSet_.size()));
  }

  /* Get all the planes that conflict with less than "threshold"
   * number of cells in the cutting. */
  PlaneSet getAllLightIntersectingPlanes(int i,
                                         const Cutting& cutting,
                                         int threshold);

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
