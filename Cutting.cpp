#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Triangulation_3.h>
#include <CGAL/algorithm.h>
#include <CGAL/convex_hull_3.h>
#include <CGAL/point_generators_3.h>
#include <algorithm>

#include "Cutting.h"
#include "Utils.h"

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel  K;
typedef CGAL::Polyhedron_3<K>                     Polyhedron_3;
typedef K::Segment_3                              Segment_3;
typedef K::Point_3                                Point_3;
typedef Polyhedron_3::Plane_3                     Plane_3;
typedef CGAL::Creator_uniform_3<double, Point_3>  PointCreator;
typedef CGAL::Triangulation_3<K>      Triangulation;

struct Plane_from_facet {
  Polyhedron_3::Plane_3 operator()(Polyhedron_3::Facet& f) {
    Polyhedron_3::Halfedge_handle h = f.halfedge();
    return Polyhedron_3::Plane_3(h->vertex()->point(),
                                 h->next()->vertex()->point(),
                                 h->opposite()->vertex()->point());
  }
};

Point_3 Plane_3ToPoint(const Plane_3& plane) {
  return Point_3(-(plane.a()/plane.c()),
                 -(plane.b()/plane.c()),
                 -(plane.d()/plane.c()));
}

Cutting::Cutting(int i, int level, const PlaneSet& planes) {
  i_ = i;
  level_ = level;
  
  vector<shared_ptr<Plane>> v(planes.begin(), planes.end());
  int size = ceil(((double)planes.size())/pow(2,i));
  random_shuffle(v.begin(), v.end());

  vector<Point_3> pointSet;
  Polyhedron_3 poly;

  // Get all the necessary planes.
  for (auto it = v.begin(); it != v.end() + size && it != v.end(); it++) {
    pointSet.push_back(Point_3((*it)->a_, (*it)->b_, (*it)->c_));
  }

  // Build polyhedron.
  CGAL::convex_hull_3(pointSet.begin(), pointSet.begin() + size, poly);

  // Transform facet into planes.
  transform(poly.facets_begin(), poly.facets_end(), poly.planes_begin(), Plane_from_facet());

  vector<Plane_3> planesToCheck;
  copy(poly.planes_begin(), poly.planes_end(), planesToCheck.begin());

  // Remove all facing downward planes.
  planesToCheck.erase(
      remove_if(planesToCheck.begin(),
                planesToCheck.end(),
                [](Plane_3& p) {
                  return p.orthogonal_vector().z() < 0;
                }),
      planesToCheck.end());

  vector<Point_3> outPoint;
  for (auto&& plane : planesToCheck) {
    outPoint.push_back(std::move(Plane_3ToPoint(plane)));
  }

  Triangulation T(outPoint.begin(), outPoint.end());
  
}

Cutting::Cutting() {

}
