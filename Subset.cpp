#include <algorithm>
#include <cmath>

#include "Subset.h"

using namespace std;

#define C 1
#define C_DOUBLE_PRIME 5

Subset::Subset() { }

Subset::Subset(const PlaneSet& planes) {
  for (auto plane : planes) {
    insertPlane(plane);
  }
}

Subset::Subset(shared_ptr<Plane> plane) {
  insertPlane(plane);
}

void Subset::insertPlane(shared_ptr<Plane> plane) {
  planeSet_.insert(plane);
}

void Subset::construct() {
  // Resize
  int setListSize = ceil(log2(planeSet_.size())) + 1;
  setList_.resize(setListSize);
  cuttingList_.resize(setListSize);

  // Build S_i
  for (int i = 1; i < setListSize; i++) {
    // TODO (hicder): fix this once David implement his code.
    cuttingList_[i] = make_shared<Cutting>();
    setList_[i].clear();

    for (auto cell : cuttingList_[i]->cells_) {
      cell->computeConflict(setList_[i]);
      cell->j_ = 0;
    }
  }

  // Build S_live and S_static
  liveSet_ = setList_[setListSize - 1];
  staticSet_ = setList_[setListSize - 1];
}

PlaneSet Subset::deletePlane(shared_ptr<Plane> plane) {
  PlaneSet deletedPlanes; 
  planeSet_.erase(plane);
  liveSet_.erase(plane);
  for (int i = 0; i < planeSet_.size(); i++) {
    for (auto cell : cuttingList_[i]->cells_) {
      if (cell->isInConflictList(plane)) {
        cell->j_++;

        int threshold = ceil(cell->getConflictListSize() / C_DOUBLE_PRIME);
        if (cell->j_ == threshold) {
          for (auto it = liveSet_.begin(); it != liveSet_.end();) {
            if (cell->isInConflictList(*it)) {
              it = liveSet_.erase(it);
              deletedPlanes.insert(*it);
            } else {
              it++;
            }
          }
        }
      }
    }
  }
  return deletedPlanes;
}

shared_ptr<Subset> Subset::getDiff() {
  // TODO (hicder): FIX this.
  return make_shared<Subset>();
}
