#include "plane.h"

using namespace std;

Plane::Plane(double px, double py) {
  this->a = 2*px;
  this->b = 2*py;
  this->c = -1 * (px*px + py*py);
}

Plane::Plane(double a, double b, double c) {
  this->a = a;
  this->b = b;
  this->c = c;
}

pair<double, double> Plane::toPoint() {
  return make_pair(a/2, b/2);
}

bool Plane::operator==(const Plane& other) const {
  return (a == other.a) && (b == other.b) && (c == other.c);
}

bool Plane::operator< (const Plane& other) const {
  if (a != other.a) {
    return a < other.a;
  }

  if (b != other.b) {
    return b < other.b;
  }

  if (c != other.c) {
    return c < other.c;
  }

  return false;
}
