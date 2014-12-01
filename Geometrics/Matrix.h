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
    Matrix() {
      generateZeroArray(0, 0);
    }
    Matrix(const int rows, const int cols) {
      generateZeroArray(rows, cols);
    }
    explicit Matrix(const CMatrix<T>& cm) {
      generateZeroArray(cm.ySize(), cm.xSize());
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++)
          this->at(i, j) = cm(j, i);
      }
    }
    Matrix(const Matrix& orig) {
      _rows = orig._rows;
      _cols = orig._cols;
      _data = new T[_rows * _cols];
      for (int i = 0; i < _rows * _cols; i++)
        _data[i] = orig._data[i];
    }
    /**
     * You can create a two dimensional array like this:
     * b[][2] = { {4, 5}, {2, 3} };
     * And to create a Matrix you just call Matrix(b[0], 2, 2).
     *
     * @param a The first element of the array(e.g. array[0]).
     * @param rows The rows of the given array.
     * @param cols The columns of the given array.
     */
    Matrix(T* a, const int rows, const int cols) {
      generateZeroArray(rows, cols);
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          T tmp = *(a + i * cols + j);
          this->at(i, j) = tmp;
        }
      }
    }
    CMatrix<T> convertToCMatrix() {
      CMatrix<T> m(_cols, _rows);
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          m(j, i) = this->at(i, j);
        }
      }
      return m;
    }
    virtual ~Matrix() {
      delete [] _data;
    }
    /**
     * Add the scalar value v to all entries of the matrix.
     * @param v The scalar value.
     * @return A matrix with all entries added by the value.
     */
    const Matrix operator+(const T v) {
      Matrix res(_rows, _cols);
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          res(i, j) = this->at(i, j) + v;
        }
      }
      return res;
    }
    void clipValues(const T min, const T max) {
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          if (this->at(i, j) < min)
            this->at(i, j) = min;
          else if (this->at(i, j) > max)
            this->at(i, j) = max;
        }
      }
    }
    /**
     * Add the scalar value v to all entries of the matrix.
     * @param v The scalar value.
     * @return The matrix with all entries added by the value.
     */
    Matrix& operator+=(const T v) {
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          this->at(i, j) += v;
        }
      }
      return *this;
    }
    /**
     * Add the Matrix m and this Matrix.
     * @param v The scalar value.
     * @return A matrix which is the sum of the two matrices.
     */
    const Matrix operator+(const Matrix& m) {
      Matrix res(_rows, _cols);
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          res(i, j) = this->at(i, j) + m(i, j);
        }
      }
      return res;
    }
    /**
     * Add the Matrix m to this Matrix
     * @param v The scalar value.
     * @return This matrix added by the Matrix m.
     */
    Matrix& operator+=(const Matrix& m) {
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          this->at(i, j) += m(i, j);
        }
      }
      return *this;
    }
    Matrix& operator= (Matrix m) {
      swap(m);
      return *this;
    }
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    T& operator()(const int i, const int j) {
      assert(0 <= i && i < _rows);
      assert(0 <= j && j < _cols);
      return _data[i * _cols + j];
    }
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column. Constant variant.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    const T& operator()(const int i, const int j) const {
      assert(0 <= i && i < _rows);
      assert(0 <= j && j < _cols);
      return _data[i * _cols + j];
    }
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    T& at(const int i, const int j) {
      return this->operator ()(i, j);
    }
    /**
     * Return the value at position i and j. Where i describes the row and j
     * the column. Constant variant.
     * @param i row
     * @param j column
     * @return Value at position i and j.
     */
    const T& at(const int i, const int j) const {
      return this->operator ()(i, j);
    }
    Matrix trans() {
      Matrix<T> res(_cols, _rows);
      for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _cols; j++) {
          res(j, i) = this->at(i, j);
        }
      }
      return res;
    }

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
    void swap(Matrix& m) {
      // swap all the members  with m
      std::swap(_data, m._data);
      std::swap(_rows, m._rows);
      std::swap(_cols, m._cols);
    }
    void generateZeroArray(const int rows, const int cols) {
      _rows = rows;
      _cols = cols;
      _data = new T[_rows * _cols];
      for (int i = 0; i < _rows * _cols; i++)
        _data[i] = 0;
    }
    T* _data;
  };
}

#endif  // GEOMETRICS_MATRIX_H_

