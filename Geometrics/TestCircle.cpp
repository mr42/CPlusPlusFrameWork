/**
 * @file    CircleTest.cpp
 * @author  michael <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright 23. März 2014 University of Freiburg
 * 
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 * 
 */

#include <gtest/gtest.h>
#include "./Point.h"
#include "./Circle.h"
using Geometrics::Point;
using Geometrics::Circle;

// _________________________________________________
TEST(CircleTest, constructor) {
  // Test for int
  Circle<> ci4(Point<>(4, 43, 21, 3, 795), 5);
  EXPECT_EQ(43, ci4._center[0]);
  EXPECT_EQ(21, ci4._center[1]);
  EXPECT_EQ(3, ci4._center[2]);
  EXPECT_EQ(795, ci4._center[3]);
  EXPECT_EQ(5, ci4._radius);
  // Test for float
  Circle<float> cf3(Point<float>(3, 4.43, 8.493, 5.4), 6.354);
  EXPECT_FLOAT_EQ(4.43, cf3._center[0]);
  EXPECT_FLOAT_EQ(8.493, cf3._center[1]);
  EXPECT_FLOAT_EQ(5.4, cf3._center[2]);
  EXPECT_FLOAT_EQ(6.354, cf3._radius);
}


