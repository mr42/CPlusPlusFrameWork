/**
 * @file    Matrix.cpp
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
 * The Matrix.cpp desc.
 */

#include "./Matrix.h"

namespace Geometrics {
  template <class T>
  Matrix<T>::Matrix() {}

  template <class T>
  Matrix<T>::Matrix(const int rows, const int cols) {
    generateZeroArray(rows, cols);
  }

  template <class T>
  Matrix<T>::Matrix(const Matrix<T>& orig) {
  }

  template <class T>
  void Matrix<T>::generateZeroArray(const int rows, const int cols) {
    _rows = rows;
    _cols = cols;
    _data = new T*[_rows];
    for (int i = 0; i < _rows; i++) {
      _data[i] = new T[_cols];
      for (int j = 0; j < _cols; j++)
        _data[i][j] = 0;
    }
  }

  template <class T>
  Matrix<T>::Matrix(const CMatrix<T>& cm) {
    generateZeroArray(cm.ySize(), cm.xSize());
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++)
        _data[i][j] = cm(j, i);
    }
  }

  template <class T>
  CMatrix<T> Matrix<T>::convertToCMatrix() {
    CMatrix<T> m(_cols, _rows);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        m(j, i) = _data[i][j];
      }
    }
    return m;
  }

  template <class T>
  Matrix<T>::~Matrix() {
    for (int j = 0; j < _rows; j++)
      delete [] _data[j];
    delete [] _data;
  }

  template class Matrix<float>;
}

