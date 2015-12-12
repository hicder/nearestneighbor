#pragma once

#include <cmath>
#include <iostream>
#include <set>
#include <vector>

#include "Cell.h"
#include "Plane.h"

/**
 * This contains the cutting and all the vertical decompositions (cells).
 */
class Cutting {
 public:
  Cutting(int i, int level, const PlaneSet& planes);

  /* This is only used for temporary silence of error. Should be remove later.*/
  Cutting();

  int numOfConflictCell(std::shared_ptr<Plane> plane) const;

 public:
  /* (1/2^i) cutting. */
  int i_;

  /* level of the cutting. */
  int level_;

  /* cell \delta */
  std::vector<std::shared_ptr<Cell>> cells_;
};
