#include <gtest/gtest.h>
#include <utility>
#include <set>

#include "plane.h"

using namespace std;

namespace {

// The fixture for testing class Foo.
class PlaneTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  PlaneTest() {
    // You can do set-up work for each test here.
  }

  virtual ~PlaneTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Foo.
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(PlaneTest, ToPoint) {
  Plane plane(4, 2, 2);
  std::pair<double, double> plane2d = plane.toPoint();
  EXPECT_EQ(2, plane2d.first);
  EXPECT_EQ(1, plane2d.second);
}

TEST_F(PlaneTest, EqualsOperator) {
  Plane plane(4, 2, 2);
  Plane plane2(4, 2, 2);
  EXPECT_EQ(true, plane == plane2);
}

TEST_F(PlaneTest, EqualsOperatorSet) {
  Plane plane(4, 2, 2);
  Plane plane2(4, 2, 2);
  Plane plane3(5, 2, 2);
  std::set<Plane> planeSet;
  planeSet.insert(plane);
  planeSet.insert(plane2);
  planeSet.insert(plane3);
  EXPECT_EQ(2, planeSet.size());
}
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
