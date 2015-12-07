#pragma once

#include <iostream>
#include <set>
#include <vector>

#include "Cell.h"
#include "Plane.h"
//TODO (david): COMPLETE THIS

class Cutting {
 public:
  Cutting(int i, int level, std::set<Plane> planes);

 public:
  /* (1/2^i) cutting. */
  int i_;

  /* level of the cutting. */
  int level_;

  /* cell \delta */
  std::vector<Cell> cells_;
};
