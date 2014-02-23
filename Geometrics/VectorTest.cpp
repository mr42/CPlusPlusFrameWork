// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include "./Vector.h"
using Geometrics::Vector;

// _________________________________________________
TEST(VectorTest, constructor) {
  Vector<int> v(2, 4, 7);
  EXPECT_EQ(4, v[0]);
  EXPECT_EQ(7, v[1]);
  Vector<double> v1(2, 4.43241, 6.4325);
  EXPECT_DOUBLE_EQ(4.43241, v1[0]);
  EXPECT_DOUBLE_EQ(6.4325, v1[1]);
}

// _________________________________________________
TEST(VectorTest, operatorEqual) {
  Vector<int> v1(2, 3, 8);
  Vector<int> v2(2, 53, 493);
  EXPECT_FALSE(v1 == v2);
  v2[0] = 3;
  v2[1] = 8;
  EXPECT_TRUE(v1 == v2);
}

// ________________________________________________
TEST(VectorTest, operatorNotEqual) {
  Vector<int> v1(2, 3, 8);
  Vector<int> v2(2, 53, 493);
  EXPECT_TRUE(v1 != v2);
  v2[0] = 3;
  v2[1] = 8;
  EXPECT_FALSE(v1 != v2);
}

// ___________________________________________________
TEST(VectorTest, operatorAddition) {
  Vector<int> v1(2, 45, 83);
  Vector<int> v2(2, 534, 930);
  Vector<int> v3(2, 579, 1013);
  Vector<int> v4 = v1 + v2;
  EXPECT_TRUE(v3 == v4);
}
// ___________________________________________________
TEST(Point2D, operatorSubtraction) {
  Vector<int> v1(2, 45, 83);
  Vector<int> v2(2, 5, 90);
  Vector<int> v3(2, 40, -7);
  Vector<int> v4 = v1 - v2;
  EXPECT_TRUE(v3 == v4);
}
