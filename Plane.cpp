#include "Plane.h"
#include "Utils.h"

using namespace std;

Plane::Plane(double px, double py) {
  this->a_ = 2*px;
  this->b_ = 2*py;
  this->c_ = -1 * (px*px + py*py);
}

Plane::Plane(double a, double b, double c) {
  this->a_ = a;
  this->b_ = b;
  this->c_ = c;
}

pair<double, double> Plane::toPoint() {
  return make_pair(a_/2, b_/2);
}

bool Plane::operator==(const Plane& other) const {
  return (Utils::isEqualDouble(a_, other.a_) &&
          Utils::isEqualDouble(b_, other.b_) &&
          Utils::isEqualDouble(c_, other.c_));
}

bool Plane::operator< (const Plane& other) const {
  if (a_ != other.a_) {
    return a_ < other.a_;
  }

  if (b_ != other.b_) {
    return b_ < other.b_;
  }

  if (c_ != other.c_) {
    return c_ < other.c_;
  }

  return false;
}

Plane& Plane::operator=(const Plane& other) {
  if (this != &other) {
    this->a_ = other.a_;
    this->b_ = other.b_;
    this->c_ = other.c_;
  }

  return *this;
}
