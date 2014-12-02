/**
 * @file    GaussianFilterTest.cpp
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
 * The GaussianFilterTest.cpp desc.
 */

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "./GaussianFilter.h"
#include "../Geometrics/Matrix.h"
#include "../ImageProcessing/CMatrix.h"

using Geometrics::Matrix;
using std::vector;

namespace Filter {
  TEST(GaussianFilterTest, computeKernel) {
    GaussianFilter g;
    vector<float> res = g.computeKernel(1);
    EXPECT_FLOAT_EQ(0.39894229, res[0]);
    EXPECT_FLOAT_EQ(0.24197073, res[1]);
    EXPECT_FLOAT_EQ(0.053990968, res[2]);
    EXPECT_FLOAT_EQ(0.00443185, res[3]);
  }
  TEST(GaussianFilterTest, filter) {
    GaussianFilter g;
    CMatrix<float> cm;
    cm.readFromPGM("chinaToiletCut.pgm");
    float a[][4] = { {67, 69, 69, 67},
                    {60, 64, 64, 60},
                    {55, 60, 63, 62},
                    {56, 64, 70, 69},
                    {52, 60, 65, 61}};
    Matrix<float> res(a[0], 5, 4);
    float a2[][4] = { {64.2123, 64.6795, 64.9195, 64.6939},
                      {62.6817, 63.3948, 64.0779, 64.0519},
                      {60.56, 61.8875, 63.7011, 64.1957},
                      {59.7641, 61.6572, 64.4408, 65.3377},
                      {59.4814, 61.5618, 64.6169, 65.5943}};
    Matrix<float> exp(a2[0], 5, 4);
    res = g.filter(res, 1);
    EXPECT_TRUE(exp == res);
  }
}
