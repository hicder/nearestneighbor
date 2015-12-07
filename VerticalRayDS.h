#pragma once

#include <memory>
#include <vector>

#include "Subset.h"
#include "VerticalRay.h"

class VerticalRayDS {
 public:
  VerticalRayDS();

  /* insert a plane into the data structure. */
  void insertPlane(std::shared_ptr<Plane> plane);

  /* delete a plane from the data structure. */
  void deletePlane(std::shared_ptr<Plane> plane);

  /* return the nearest plane to the upward vertical ray. */
  std::shared_ptr<Plane> getNearestPlane(std::shared_ptr<VerticalRay> ray);

  std::vector<Subset> subsets_;
};
