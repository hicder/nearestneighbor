#include "VerticalRay.h"
#include "VerticalRayDS.h"

using namespace std;

VerticalRayDS::VerticalRayDS() { }

void VerticalRayDS::insertPlane(shared_ptr<Plane> plane) {
  // TODO (hicder): FIX this.
}

void VerticalRayDS::deletePlane(shared_ptr<Plane> plane) {
  // TODO (hicder): FIX this.
}

shared_ptr<Plane> getNearestPlane(shared_ptr<VerticalRay> ray) {
  // TODO (hicder): FIX this.
  return make_shared<Plane>(0, 0, 0);
}
