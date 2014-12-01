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

#include "../Geometrics/Matrix.h"

using Geometrics::Matrix;

namespace Filter {
  class GaussianFilter {
  public:
    GaussianFilter() {}
    GaussianFilter(const GaussianFilter& orig) {}
    template <class T>
    Matrix<T> filter(const Matrix<T>& m) const {
      Matrix<T> res(m._rows, m._cols);
      return res;
    }
    virtual ~GaussianFilter() {}
  private:
  };
}

#endif  // FILTER_GAUSSIANFILTER_H_

