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
#include "./Matrix.h"

using Geometrics::Matrix;

TEST(MatrixTest, operatorAssign) {
  Matrix<float> m(3, 3);
  EXPECT_EQ(3, m._rows);
  EXPECT_EQ(3, m._cols);
  for (int i = 0; i < m._rows; i++)
    for (int j = 0; j < m._cols; j++)
      EXPECT_EQ(0, m(i, j));
}
