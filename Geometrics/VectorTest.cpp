// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include "./Vector.h"
using Geometrics::Vector;

// _________________________________________________
TEST(VectorTest, constructor) {
  // Test for int
  int i2[] = {4, 7};
  Vector<> vi2(i2, 2);
  EXPECT_EQ(4, vi2[0]);
  EXPECT_EQ(7, vi2[1]);
  int i4[] = {43, 21, 3, 795};
  Vector<> vi4(i4, 4);
  EXPECT_EQ(43, vi4[0]);
  EXPECT_EQ(21, vi4[1]);
  EXPECT_EQ(3, vi4[2]);
  EXPECT_EQ(795, vi4[3]);
  // Test for float
  float f2[] = {4.43, 8.493};
  Vector<float> vf2(f2, 2);
  EXPECT_FLOAT_EQ(4.43, f2[0]);
  EXPECT_FLOAT_EQ(8.493, f2[1]);
  // Test for double
  double d2[] = {4.43241, 6.4325};
  Vector<double> v1(d2, 2);
  EXPECT_DOUBLE_EQ(4.43241, d2[0]);
  EXPECT_DOUBLE_EQ(6.4325, d2[1]);
  // Test for unsigned int
  unsigned int ui2[] = {34, 98};
  Vector<unsigned int> vu3(ui2, 2);
  EXPECT_EQ(34, ui2[0]);
  EXPECT_EQ(98, ui2[1]);
}

// _________________________________________________
TEST(VectorTest, operatorEqual) {
  int i21[] = {3, 8};
  int i22[] = {53, 493};
  Vector<> v1(i21, 2);
  Vector<> v2(i22, 2);
  EXPECT_FALSE(v1 == v2);
  v2[0] = 3;
  v2[1] = 8;
  EXPECT_TRUE(v1 == v2);
}

// ________________________________________________
TEST(VectorTest, operatorNotEqual) {
  int i21[] = {3, 8};
  int i22[] = {53, 493};
  Vector<> v1(i21, 2);
  Vector<> v2(i22, 2);
  int i;
  EXPECT_TRUE(v1 != v2);
  v2[0] = 3;
  v2[1] = 8;
  EXPECT_FALSE(v1 != v2);
}

// ___________________________________________________
TEST(VectorTest, operatorAddition) {
  int i21[] = {45, 83};
  int i22[] = {534, 930};
  int iresult2[] = {579, 1013};
  Vector<> v1(i21, 2);
  Vector<> v2(i22, 2);
  Vector<> v3(iresult2, 2);
  Vector<> v4 = v1 + v2;
  EXPECT_TRUE(v3 == v4);
}
// ___________________________________________________
TEST(Point2D, operatorSubtraction) {
  int i21[] = {45, 83};
  int i22[] = {5, 90};
  int iresult2[] = {40, -7};
  Vector<> v1(i21, 2);
  Vector<> v2(i22, 2);
  Vector<> v3(iresult2, 2);
  Vector<> v4 = v1 - v2;
  EXPECT_TRUE(v3 == v4);
}