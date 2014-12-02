/**
 * @file    GaussianFilter.h
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
 * The GaussianFilter.h desc.
 */

#ifndef FILTER_GAUSSIANFILTER_H_
#define FILTER_GAUSSIANFILTER_H_

#include <gtest/gtest.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "../Geometrics/Matrix.h"

using Geometrics::Matrix;
using std::vector;

namespace Filter {
  class GaussianFilter {
  public:
    GaussianFilter() {}
    GaussianFilter(const GaussianFilter& orig) {}
    template <class T>
    Matrix<T> filter(const Matrix<T>& m, const int sigma) const {
      // TODO(mr42): Problems with small images and high sigma, since the mirroring
      // makes problems.
      vector<float> kernel = computeKernel(sigma);
      Matrix<T> res = filter(m, kernel);
      res.clipValues(0, 255);
      res = res.trans();
      res = filter(res, kernel);
      res.clipValues(0, 255);
      res = res.trans();
      return res;
    }
    virtual ~GaussianFilter() {}
  private:
    template <class T>
    Matrix<T> filter(const Matrix<T>& m, const vector<float>& kernel) const {
      Matrix<T> res(m._rows, m._cols);
      for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols; j++) {
          // mean
          res(i, j) += kernel[0] * m(i, j);
          // left from mean
          for (size_t k = 1; k < kernel.size(); k++) {
            int c = j - k;
            if (c < 0) c = -1 * c;
            res(i, j) += kernel[k] * m(i, c);
          }
          // right from mean
          for (size_t k = 1; k < kernel.size(); k++) {
            int c = j + k;
            if (c >= m._cols) c = 2 * (m._cols - 1) - c;
            res(i, j) += kernel[k] * m(i, c);
          }
        }
      }
      return res;
    }
    vector<float> computeKernel(const float sigma) const {
      // compute gaussian kernel
      vector<float> kernel(3 * sigma + 1);
      // The sum for the normalization
      float norm = 1./(sqrt(2 * M_PI) * sigma);
      for (size_t i = 0; i < kernel.size(); i++) {
        kernel[i] = norm *
                    exp(-((i * i) / (2 * sigma * sigma)));
      }
      return kernel;
    }
    FRIEND_TEST(GaussianFilterTest, computeKernel);
  };
}

#endif  // FILTER_GAUSSIANFILTER_H_
