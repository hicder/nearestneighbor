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

void VerticalRayDS::deletePlane(shared_ptr<Plane> h) {
  PlaneSet A;
  for(auto&& it:subsets_) {
    if(it->planeSet_.count(h) >= 1) {
      PlaneSet deletedPlanes = it->deletePlane(h);
      A.insert(deletedPlanes.begin(), deletedPlanes.end());
    }
  }

  if(A.count(h) >= 1) {
    A.erase(h);
  }

  for(auto&& it : A)  {
    insertPlane(it);
  }
}

shared_ptr<Plane> VerticalRayDS::getNearestPlane(double x, double y) {
  PlaneSet B;
  for(auto&& it:subsets_) {
    shared_ptr<Plane> lowPlane = Utils::getLowestPlaneInSet(it->staticSet_, x, y);
    if(it->liveSet_.count(lowPlane)) {
      B.insert(lowPlane);
    }
  }
  return Utils::getLowestPlaneInSet(B, x, y);
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
  for (auto it = depthMap_.begin(); it != depthMap_.end();) {
    if (it->second.size() == b) {
      // We will clean up from the beginning, and return.
      // I don't think the recursion level would be too deep.
      // It should be bounded by logn, which is at most 32.
      PlaneSet combinedLive;
      for (auto&& s : it->second) {
        combinedLive.insert(s->liveSet_.begin(), s->liveSet_.end());
        subsets_.erase(remove(subsets_.begin(), subsets_.end(), s),
                       subsets_.end());
      }
      it = depthMap_.erase(it);
      shared_ptr<Subset> combinedSubset = make_shared<Subset>(combinedLive);
      preprocess(combinedSubset);
      cleanup();
      return;
    } else {
      it++;
    }
  }
}
