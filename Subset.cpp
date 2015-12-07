#include "Subset.h"

using namespace std;

Subset::Subset() { }

Subset::Subset(const set<shared_ptr<Plane>>& planes) {
  for (auto plane : planes) {
    insertPlane(plane);
  }
}

void Subset::insertPlane(shared_ptr<Plane> plane) {
  planeSet_.insert(plane);
}

