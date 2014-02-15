// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include "./Point2D.h"

using Geometrics::Point2D;

// _________________________________________________
TEST(PointTest, constructor) {
  Point2D<int> p(4, 7);
  EXPECT_EQ(4, p._x);
  EXPECT_EQ(7, p._y);
  Point2D<float> p1(4.43241, 6.4325);
  EXPECT_FLOAT_EQ(4.43241, p1._x);
  EXPECT_FLOAT_EQ(6.4325, p1._y);
}

// _________________________________________________
TEST(PointTest, operatorEqual) {
  Point2D<int> p1(3, 8);
  Point2D<int> p2(53, 493);
  EXPECT_FALSE(p1 == p2);
  p2._x = 3;
  p2._y = 8;
  EXPECT_TRUE(p1 == p2);
}
