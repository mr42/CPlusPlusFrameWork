/**
 * @file    MatrixTest.cpp
 * @author  mich <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright November 20, 2014 University of Freiburg
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
 * @section DESCRIPTION
 *
 * The MatrixTest.cpp desc.
 */

#include <gtest/gtest.h>
#include <iostream>
#include "./Matrix.h"

namespace Geometrics {
  TEST(MatrixTest, constructor) {
    int a[][2] = { {4, 5}, {2, 3}};
    Matrix<> mArray(a[0], 2, 2);
    EXPECT_EQ(4, mArray(0, 0));
    EXPECT_EQ(5, mArray(0, 1));
    EXPECT_EQ(2, mArray(1, 0));
    EXPECT_EQ(3, mArray(1, 1));
    EXPECT_EQ(2, mArray._rows);
    EXPECT_EQ(2, mArray._cols);
  }
  TEST(MatrixTest, clipValues) {
    int a[][3] = { {0, 255, 120}, {-1, 256, 30}};
    Matrix<> m(a[0], 2, 3);
    m.clipValues(0, 255);
    EXPECT_EQ(0, m(0, 0));
    EXPECT_EQ(255, m(0, 1));
    EXPECT_EQ(120, m(0, 2));
    EXPECT_EQ(0, m(1, 0));
    EXPECT_EQ(255, m(1, 1));
    EXPECT_EQ(30, m(1, 2));
    EXPECT_EQ(2, m._rows);
    EXPECT_EQ(3, m._cols);
  }

  TEST(MatrixTest, operatorAdd) {
    int a[][2] = { {4, 5}, {2, 3}};
    Matrix<> tmp(a[0], 2, 2);
    Matrix<> m = tmp + 4;
    EXPECT_EQ(8, m(0, 0));
    EXPECT_EQ(9, m(0, 1));
    EXPECT_EQ(6, m(1, 0));
    EXPECT_EQ(7, m(1, 1));
    m += 2;
    EXPECT_EQ(10, m(0, 0));
    EXPECT_EQ(11, m(0, 1));
    EXPECT_EQ(8, m(1, 0));
    EXPECT_EQ(9, m(1, 1));
    m += m;
    EXPECT_EQ(20, m(0, 0));
    EXPECT_EQ(22, m(0, 1));
    EXPECT_EQ(16, m(1, 0));
    EXPECT_EQ(18, m(1, 1));
    m = m + tmp;
    EXPECT_EQ(24, m(0, 0));
    EXPECT_EQ(27, m(0, 1));
    EXPECT_EQ(18, m(1, 0));
    EXPECT_EQ(21, m(1, 1));
  }

  TEST(MatrixTest, trans) {
    int a[][3] = { {3, 4, 3}, {1, 2, 3} };
    Matrix<> m(a[0], 2, 3);
    Matrix<> t = m.trans();
    EXPECT_EQ(3, t._rows);
    EXPECT_EQ(2, t._cols);
    EXPECT_EQ(m(0, 0), t(0, 0));
    EXPECT_EQ(m(0, 1), t(1, 0));
    EXPECT_EQ(m(0, 2), t(2, 0));
    EXPECT_EQ(m(1, 0), t(0, 1));
    EXPECT_EQ(m(1, 1), t(1, 1));
    EXPECT_EQ(m(1, 2), t(2, 1));
  }

  TEST(MatrixTest, operatorEqual) {
    int a[][3] = { {3, 4, 3}, {1, 2, 3} };
    int a2[][3] = { {3, 4, 0}, {1, 2, 3} };
    Matrix<> m(a[0], 2, 3);
    Matrix<> m2(a2[0], 2, 3);
    Matrix<> m3(a[0], 2, 3);
    EXPECT_TRUE(m == m3);
    EXPECT_FALSE(m == m2);
  }

  TEST(MatrixTest, operatorNotEqual) {
    int a[][3] = { {3, 4, 3}, {1, 2, 3} };
    int a2[][3] = { {3, 4, 0}, {1, 2, 3} };
    Matrix<> m(a[0], 2, 3);
    Matrix<> m2(a2[0], 2, 3);
    Matrix<> m3(a[0], 2, 3);
    EXPECT_FALSE(m != m3);
    EXPECT_TRUE(m != m2);
  }
  TEST(MatrixTest, operatorAssign) {
    Matrix<int> m(3, 3);
    EXPECT_EQ(3, m._rows);
    EXPECT_EQ(3, m._cols);
    for (int i = 0; i < m._rows; i++)
      for (int j = 0; j < m._cols; j++)
        EXPECT_EQ(0, m(i, j));
    Matrix<int> m2 = Matrix<int>(2, 4);
    m(1, 2) = 6;
    m2(1, 2) = 4;
    EXPECT_EQ(4, m2(1, 2));
    m2 = m;
    EXPECT_EQ(3, m2._rows);
    EXPECT_EQ(3, m2._cols);
    EXPECT_EQ(6, m2(1, 2));
  }
}
