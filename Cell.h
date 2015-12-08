#pragma once
#include <memory>
#include <set>
#include <vector>

#include "Plane.h"
#include "Point.h"
#include "Utils.h"
class Cell {
 public:
  Cell();

  void computeConflict(const PlaneSet&);

  bool isInConflictList(const std::shared_ptr<Plane>);

  int getConflictListSize() const;
 public:
  std::vector<std::shared_ptr<Point>> vertices_;

  /* j_delta*/
  int j_;

  PlaneSet conflictList_;
};
