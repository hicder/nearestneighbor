#pragma once
#include <memory>
#include <set>
#include <vector>

#include "Plane.h"
#include "Point.h"
#include "Utils.h"

/**
 * class Cell
 * Represented by a top triangle and vertical prism.
 */
class Cell {
 public:
  Cell();

  /* Compute the conflict lists with the plane set.*/
  void computeConflict(const PlaneSet&);

  /* Returns true if this cell conflicts with the plane. */
  bool isInConflictList(const std::shared_ptr<Plane>);

  /* Get size of conflict list.*/
  int getConflictListSize() const;

  /* Insert vertices of this cell. */
  void insertPoints(const std::vector<std::shared_ptr<Point>>& points);

 public:
  /* Vertices of the top cell. This should only have 3 vertices.*/
  std::vector<std::shared_ptr<Point>> vertices_;

  /* j_delta*/
  int j_;

  PlaneSet conflictList_;
};
