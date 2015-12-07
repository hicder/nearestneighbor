#include "VerticalRay.h"
#include "VerticalRayDS.h"

using namespace std;

static const int b = 16;

VerticalRayDS::VerticalRayDS() { }

void VerticalRayDS::insertPlane(shared_ptr<Plane> plane) {
  shared_ptr<Subset> subset = make_shared<Subset>(plane);
  subset->liveSet_ = subset->planeSet_;
  subset->staticSet_ = subset->planeSet_;
  subsets_.push_back(subset);
  depthMap_[subset->depth()].insert(subset);

  cleanup();
}

void VerticalRayDS::deletePlane(shared_ptr<Plane> plane) {
  // TODO (hicder): FIX this.
}

shared_ptr<Plane> VerticalRayDS::getNearestPlane(shared_ptr<VerticalRay> ray) {
  // TODO (hicder): FIX this.
  return make_shared<Plane>(0, 0, 0);
}

void VerticalRayDS::preprocess(shared_ptr<Subset> subset) {
  if (!subset->isEmpty()) {
    subsets_.push_back(subset);
    subset->construct();
    depthMap_[subset->depth()].insert(subset);

    preprocess(subset->getDiff());
  }
}

void VerticalRayDS::cleanup() {
  // TODO (hicder): FIX this.
  for (auto&& it : depthMap_) {
    if (it.second.size() == b) {

    }
  }
}
