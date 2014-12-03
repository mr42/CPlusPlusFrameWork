/**
 * @file    Filter.h
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
 * The Filter.h desc.
 */

#ifndef FILTER_FILTER_H_
#define FILTER_FILTER_H_

#include <vector>
#include "../Geometrics/Matrix.h"

using Geometrics::Matrix;
using std::vector;

namespace Filter {
  class Filter {
  public:
    Filter() {}
    Filter(const Filter& orig) {}
    virtual ~Filter() {}
  protected:
    template <class T>
    Matrix<T> filterX(const Matrix<T>& m, const vector<float>& kernel) const {
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
    template <class T>
    Matrix<T> filterY(const Matrix<T>& m, const vector<float>& kernel) const {
      Matrix<T> res(m._rows, m._cols);
      for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols; j++) {
          // mean
          res(i, j) += kernel[0] * m(i, j);
          // left from mean
          for (size_t k = 1; k < kernel.size(); k++) {
            int r = i - k;
            if (r < 0) r = -1 * r;
            res(i, j) += kernel[k] * m(r, j);
          }
          // right from mean
          for (size_t k = 1; k < kernel.size(); k++) {
            int r = i + k;
            if (r >= m._rows) r = 2 * (m._rows - 1) - r;
            res(i, j) += kernel[k] * m(r, j);
          }
        }
      }
      return res;
    }
  };
}
#endif  // FILTER_FILTER_H_

