#include <gtest/gtest.h>
#include <utility>
#include <set>
#include <fstream>

#include "../Cutting.h"
#include "../Utils.h"
#include "../VerticalRayDS.h"

using namespace std;

namespace {

// The fixture for testing class Foo.
class IntegrationTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  IntegrationTest() {
    // You can do set-up work for each test here.
  }

  virtual ~IntegrationTest() {
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
TEST_F(IntegrationTest, checkEverything) {
  ifstream in("test/planes.txt");
  double a, b, c;
  VerticalRayDS rayDS;
  while(in >> a >> b >> c) {
    shared_ptr<Plane> plane = make_shared<Plane>(a, b, c);
    rayDS.insertPlane(plane);
  }

  shared_ptr<Plane> nearest = rayDS.getNearestPlane(0,0);
  shared_ptr<Plane> expected = make_shared<Plane>(0,0,1000);
  EXPECT_EQ(*expected, *nearest);
}

TEST_F(IntegrationTest, testRemovePlane) {
  ifstream in("test/planes.txt");
  double a, b, c;
  VerticalRayDS rayDS;
  while(in >> a >> b >> c) {
    shared_ptr<Plane> plane = make_shared<Plane>(a, b, c);
    rayDS.insertPlane(plane);
  }

  shared_ptr<Plane> delPlane = make_shared<Plane>(0, 0, 1000);
  rayDS.deletePlane(delPlane);

  shared_ptr<Plane> nearest = rayDS.getNearestPlane(0, 0);
  EXPECT_EQ(100, nearest->c_);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
