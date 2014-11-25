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

#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "../ImageProcessing/CMatrix.h"

using std::string;
using std::ostream;

namespace Geometrics {
  template <class T = int>
  class Matrix {
  public:
    Matrix();
    explicit Matrix(const CMatrix<T>& cm);
    Matrix(const int rows, const int cols);
    Matrix(const Matrix& orig);
    /**
     * You can create a two dimensional array like this:
     * b[][2] = { {4, 5}, {2, 3} };
     * And to create a Matrix you just call Matrix(b[0], 2, 2).
     *
     * @param a The first element of the array(e.g. array[0]).
     * @param rows The rows of the given array.
     * @param cols The columns of the given array.
     */
    Matrix(T* a, const int rows, const int cols);
    CMatrix<T> convertToCMatrix();
    virtual ~Matrix();
    Matrix& operator= (Matrix m);
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
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    T& at(const int i, const int j);
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column. Constant variant.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    const T& at(const int i, const int j) const;

    /**
     * Print the Matrix to the console in the octave format.
     */
    friend ostream& operator<<(ostream& os, const Matrix& m) {
      os << "[";
      for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols - 1; j++) {
          os << m(i, j) << " ";
        }
        os << m(i, m._cols - 1);
        if (i == m._rows - 1)
          os << "]";
        else
          os << ";";
        os << std::endl;
      }
      return os;
    }
    int _rows;
    int _cols;
  private:
    void swap(Matrix& m);
    void generateZeroArray(const int rows, const int cols);
    T* _data;
  };
}

#endif  // GEOMETRICS_MATRIX_H_

