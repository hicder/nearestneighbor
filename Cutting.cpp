#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Triangulation_3.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/algorithm.h>
#include <CGAL/convex_hull_3.h>
#include <CGAL/point_generators_3.h>
#include <algorithm>
#include <map>

#include "Cutting.h"
#include "Utils.h"

using namespace std;

// 3D
typedef CGAL::Exact_predicates_inexact_constructions_kernel  K;
typedef CGAL::Polyhedron_3<K>                     Polyhedron_3;
typedef K::Segment_3                              Segment_3;
typedef K::Point_3                                Point_3;
typedef Polyhedron_3::Plane_3                     Plane_3;
typedef CGAL::Creator_uniform_3<double, Point_3>  PointCreator;
typedef CGAL::Triangulation_3<K>      Triangulation;

// 2D
typedef CGAL::Delaunay_triangulation_2<K>        Delaunay;
typedef Delaunay::Point                          Point_2;
typedef pair<pair<double, double>, double>       pdd;
typedef pair<double, double>                     pd;

struct Plane_from_facet {
  Polyhedron_3::Plane_3 operator()(Polyhedron_3::Facet& f) {
    Polyhedron_3::Halfedge_handle h = f.halfedge();
    return Polyhedron_3::Plane_3(h->vertex()->point(),
                                 h->next()->vertex()->point(),
                                 h->opposite()->vertex()->point());
  }
};

// Helper functions
Point_2 Plane_3ToPoint(const Plane_3& plane, double& outZ) {
  outZ = -(plane.d()/plane.c());
  return Point_2(-(plane.a()/plane.c()),
                 -(plane.b()/plane.c()));
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
  transform(poly.facets_begin(),
            poly.facets_end(),
            poly.planes_begin(),
            Plane_from_facet());

  // Transform facet into planes.
  vector<Plane_3> planesToCheck;
  int count = 0;
  for (auto it = poly.planes_begin(); it != poly.planes_end(); it++, count++);
  planesToCheck.resize(count);
  copy(poly.planes_begin(), poly.planes_end(), planesToCheck.begin());

  // Remove all facing downward planes.
  planesToCheck.erase(
      remove_if(planesToCheck.begin(),
                planesToCheck.end(),
                [](Plane_3& p) {
                  return p.orthogonal_vector().z() < 0;
                }),
      planesToCheck.end());

  vector<Point_2> outPoint;
  multimap<pair<double, double>, double> p3ToZ;
  for (auto&& plane : planesToCheck) {
    double outZ;
    Point_2 p = Plane_3ToPoint(plane, outZ);
    p3ToZ.insert(pdd(pd(p.x(), p.y()), outZ));
    outPoint.push_back(p);
  }

  Delaunay T(outPoint.begin(), outPoint.end());
  for (auto it = T.finite_faces_begin();
       it != T.finite_faces_end();
       it++) {
    shared_ptr<Cell> cell = make_shared<Cell>();
    // Prepare cell's vertices
    vector<shared_ptr<Point>> points;
    for (int i = 0; i < 3; i++) {
      double x = it->vertex(i)->point().x();
      double y = it->vertex(i)->point().y();
      shared_ptr<Point> p =
        make_shared<Point>(x, y, p3ToZ.find(make_pair(x,y))->second);
      points.push_back(p);
    }
    cell->insertPoints(points);
    cell->computeConflict(planes);
    cells_.push_back(cell);
  }

}

Cutting::Cutting() {

}

int Cutting::numOfConflictCell(shared_ptr<Plane> plane) const {
  int result = 0;
  for (auto cell : cells_) {
    if (cell->isInConflictList(plane)) {
      result++;
    }
  }

  return result;
}
