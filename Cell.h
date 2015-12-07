#pragma once
#include <memory>
#include <set>
#include <vector>

#include "Plane.h"
#include "Point.h"
class Cell {
 public:
  Cell();

  void computeConflict(const std::set<std::shared_ptr<Plane>>&);

  bool isInConflictList(const std::shared_ptr<Plane>);

  int getConflictListSize() const;
 public:
  std::vector<std::shared_ptr<Point>> vertices_;

  /* j_delta*/
  int j_;

  std::set<std::shared_ptr<Plane>> conflictList_;
};
