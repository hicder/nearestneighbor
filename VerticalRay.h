#pragma once

/**
 * class VerticalRay
 * Represent a vertical ray pointing upwards.
 */
class VerticalRay {
 public:
  VerticalRay();
  VerticalRay(double x, double y, double z);

 public:
  double x_;
  double y_;
  double z_;
};
