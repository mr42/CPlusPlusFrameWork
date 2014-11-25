/**
 * @file    Matrix.h
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
 * The Matrix.h desc.
 */

#ifndef GEOMETRICS_MATRIX_H_
#define GEOMETRICS_MATRIX_H_

#include <string>
#include "../ImageProcessing/CMatrix.h"

using std::string;

namespace Geometrics {
  template <class T>
  class Matrix {
  public:
    Matrix();
    explicit Matrix(const CMatrix<T>& cm);
    Matrix(const int rows, const int cols);
    explicit Matrix(const Matrix<T>& orig);
    CMatrix<T> convertToCMatrix();
    virtual ~Matrix();
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    T& operator()(const int i, const int j);
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column. Constant variant.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    const T& operator()(const int i, const int j) const;
    int _rows;
    int _cols;
  private:
    void generateZeroArray(const int rows, const int cols);
    T** _data;
  };
}

#endif  // GEOMETRICS_MATRIX_H_

