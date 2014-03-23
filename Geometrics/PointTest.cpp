// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include "./Point.h"
using Geometrics::Point;

// _________________________________________________
TEST(PointTest, constructor) {
  // Test for int
  Point<> vi2(2, 4, 7);
  EXPECT_EQ(4, vi2[0]);
  EXPECT_EQ(7, vi2[1]);
  Point<> vi4(4, 43, 21, 3, 795);
  EXPECT_EQ(43, vi4[0]);
  EXPECT_EQ(21, vi4[1]);
  EXPECT_EQ(3, vi4[2]);
  EXPECT_EQ(795, vi4[3]);
  // Test for float
  Point<float> vf2(2, 4.43, 8.493);
  EXPECT_FLOAT_EQ(4.43, vf2[0]);
  EXPECT_FLOAT_EQ(8.493, vf2[1]);
  // Test for double
  Point<double> vd2(2, 4.43241, 6.4325);
  EXPECT_DOUBLE_EQ(4.43241, vd2[0]);
  EXPECT_DOUBLE_EQ(6.4325, vd2[1]);
  // Test for unsigned int
  Point<unsigned int> vu2(2, 34, 98);
  EXPECT_EQ(34, vu2[0]);
  EXPECT_EQ(98, vu2[1]);
}

// _________________________________________________
TEST(PointTest, operatorEqual) {
  Point<> v1(2, 3, 8);
  Point<> v2(2, 53, 493);
  EXPECT_FALSE(v1 == v2);
  v2[0] = 3;
  v2[1] = 8;
  EXPECT_TRUE(v1 == v2);
}

// ________________________________________________
TEST(PointTest, operatorNotEqual) {
  Point<> v1(2, 3, 8);
  Point<> v2(2, 53, 493);
  EXPECT_TRUE(v1 != v2);
  v2[0] = 3;
  v2[1] = 8;
  EXPECT_FALSE(v1 != v2);
}

// ___________________________________________________
TEST(PointTest, operatorAddition) {
  Point<> v1(2, 45, 83);
  Point<> v2(2, 534, 930);
  Point<> v3(2, 579, 1013);
  Point<> v4 = v1 + v2;
  EXPECT_TRUE(v3 == v4);
}

// ___________________________________________________
TEST(PointTest, operatorAdditionEqual) {
  // Test for int
  Point<> v21(2, 45, 83);
  Point<> v22(2, 534, 930);
  v21 += v22;
  EXPECT_EQ(579, v21[0]);
  EXPECT_EQ(1013, v21[1]);
  Point<> v41(4, 45, 8, 4, -6);
  Point<> v42(4, 3, -4, 9, 0);
  v41 += v42;
  EXPECT_EQ(48, v41[0]);
  EXPECT_EQ(4, v41[1]);
  EXPECT_EQ(13, v41[2]);
  EXPECT_EQ(-6, v41[3]);
}

// ___________________________________________________
TEST(PointTest, operatorSubtraction) {
  Point<> v1(2, 45, 83);
  Point<> v2(2, 5, 90);
  Point<> v3(2, 40, -7);
  Point<> v4 = v1 - v2;
  EXPECT_TRUE(v3 == v4);
}

// ___________________________________________________
TEST(PointTest, operatorSubtractionEqual) {
  Point<> v21(2, 45, 83);
  Point<> v22(2, 5, 90);
  v21 -= v22;
  EXPECT_EQ(40, v21[0]);
  EXPECT_EQ(-7, v21[1]);
}

// ___________________________________________________
TEST(PointTest, operatorMultiplication) {
  Point<> v41(4, 25, 3, 4, 9);
  Point<> v42(4, 5, -15, 0, 6);
  EXPECT_EQ(134, v41 * v42);
}
