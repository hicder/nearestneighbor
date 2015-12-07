#pragma once

#include <memory>
#include <vector>

#include "Subset.h"
#include "VerticalRay.h"

/**
 * class VerticalDS
 *
 * Main data structure to answer the query of vertical ray shooting.
 * This data structure is implemnted from the paper:
 * A Dynamic Data Structure for 3-d Convex Hulls and
 *  2-d Nearest Neighbor Queries
 * by Timothy Chan.
 */
class VerticalRayDS {
 public:
  VerticalRayDS();

  /* insert a plane into the data structure. */
  void insertPlane(std::shared_ptr<Plane> plane);

  /* delete a plane from the data structure. */
  void deletePlane(std::shared_ptr<Plane> plane);

  /* return the nearest plane to the upward vertical ray. */
  std::shared_ptr<Plane> getNearestPlane(std::shared_ptr<VerticalRay> ray);

 public:
  std::vector<Subset> subsets_;
};
