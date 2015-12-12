#include "Cell.h"

using namespace std;

Cell::Cell() {

}

void Cell::computeConflict(const PlaneSet& planes) {
  // The way we determine whether the cell conflicts with the plane
  // is that if one of the vertex of the cell is above the plane
  // That plane is conflicted with the cell, due to the fact that
  // the cell is a vertical prism.
  for(auto plane:planes) {
    if (Utils::isPointAbovePlane(*vertices_[0], *plane) ||
        Utils::isPointAbovePlane(*vertices_[1], *plane) ||
        Utils::isPointAbovePlane(*vertices_[2], *plane)) {
      conflictList_.insert(plane);
    }
  }
}

bool Cell::isInConflictList(const shared_ptr<Plane> plane) {
  return conflictList_.count(plane) == 1;
}

int Cell::getConflictListSize() const {
  return conflictList_.size();
}

void Cell::insertPoints(const vector<shared_ptr<Point>>& points) {
  for (auto point : points) {
    vertices_.push_back(point);
  }
}
