// Copyright by Michale Rudolph, 2014
#include <gtest/gtest.h>
#include "./Point.h"

using Geometrics::Point;
// ___________________________________________________________________________
TEST(PointTest, Constructor) {
  Point<int> p(4, 39);
  EXPECT_EQ(4, p._x);
  EXPECT_EQ(39, p._y);
  Point<float> pf(4.34223, 234.32);
  EXPECT_FLOAT_EQ(4.34223, pf._x);
  EXPECT_FLOAT_EQ(234.32, pf._y);
  Point<double> pd(3.5432664326563412, 4.4321431243215);
  EXPECT_DOUBLE_EQ(3.5432664326563412, pd._x);
  EXPECT_DOUBLE_EQ(4.4321431243215, pd._y);
}
