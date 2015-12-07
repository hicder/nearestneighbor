#pragma once

/**
 * Represent a line in 3-D plane
 * The formula for a line is:
 * x = a_1 + a_2 * t
 * y = b_1 + b_2 * t
 * z = c_1 + c_2 * t
 */
class Line {
 public:
  Line();
  Line (double a1, double a2, double b1, double b2, double c1, double c2);


  double a1_;
  double a2_;
  double b1_;
  double b2_;
  double c1_;
  double c2_;
};
