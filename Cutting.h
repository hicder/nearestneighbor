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

  /* This is only used for temporary silence of error. Should be remove later.*/
  // TODO (hicder): remove this.
  Cutting();

 public:
  /* (1/2^i) cutting. */
  int i_;

  /* level of the cutting. */
  int level_;

  /* cell \delta */
  std::vector<std::shared_ptr<Cell>> cells_;
};
