#pragma once
#include <memory>
#include <set>
#include <vector>

#include "Plane.h"
#include "Cutting.h"
/**
 * Represent a subset of plane
 */

class Subset {
 public:
  Subset();
  explicit Subset(const std::set<std::shared_ptr<Plane>>& planes);
  void insertPlane(std::shared_ptr<Plane> plane);
  void construct();
  void deletePlane(std::shared_ptr<Plane>);

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
  std::vector<Cutting> cuttingList_;
};
