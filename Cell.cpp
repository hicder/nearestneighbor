#include "Cell.h"

//TODO (david): COMPLETE THIS

using namespace std;

Cell::Cell() {

}

void Cell::computeConflict(const PlaneSet& planes) {

}

bool Cell::isInConflictList(const shared_ptr<Plane> plane) {
  return conflictList_.count(plane) == 1;
}

int Cell::getConflictListSize() const {
  return conflictList_.size();
}