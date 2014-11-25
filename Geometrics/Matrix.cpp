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

#include <algorithm>
#include "./Matrix.h"

namespace Geometrics {
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>::Matrix() {
    generateZeroArray(0, 0);
  }
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>::Matrix(const int rows, const int cols) {
    generateZeroArray(rows, cols);
  }
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>::Matrix(const Matrix<T>& orig) {
    _rows = orig._rows;
    _cols = orig._cols;
    _data = new T[_rows * _cols];
    for (int i = 0; i < _rows * _cols; i++)
      _data[i] = orig._data[i];
  }
  // ___________________________________________________________________________
  template <class T>
  T& Matrix<T>::operator()(const int i, const int j) {
    assert(0 <= i && i < _rows);
    assert(0 <= j && j < _cols);
    return _data[i + _cols * j];
  }
  // ___________________________________________________________________________
  template <class T>
  const T& Matrix<T>::operator()(const int i, const int j) const {
    assert(0 <= i && i < _rows);
    assert(0 <= j && j < _cols);
    return _data[i + _cols * j];
  }
  // ___________________________________________________________________________
  template <class T>
  T& Matrix<T>::at(const int i, const int j) {
    return this->operator ()(i, j);
  }
  // ___________________________________________________________________________
  template <class T>
  const T& Matrix<T>::at(const int i, const int j) const {
    return this->operator ()(i, j);
  }
  // ___________________________________________________________________________
  template <class T>
  void Matrix<T>::generateZeroArray(const int rows, const int cols) {
    _rows = rows;
    _cols = cols;
    _data = new T[_rows * _cols];
    for (int i = 0; i < _rows * _cols; i++)
      _data[i] = 0;
  }
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>::Matrix(const CMatrix<T>& cm) {
    generateZeroArray(cm.ySize(), cm.xSize());
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++)
        this->at(i, j) = cm(j, i);
    }
  }
  // ___________________________________________________________________________
  template <class T>
  CMatrix<T> Matrix<T>::convertToCMatrix() {
    CMatrix<T> m(_cols, _rows);
    for (int i = 0; i < _rows; i++) {
      for (int j = 0; j < _cols; j++) {
        m(j, i) = this->at(i, j);
      }
    }
    return m;
  }
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>& Matrix<T>::operator =(Matrix m) {
    swap(m);
    return *this;
  }
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>::Matrix(T* a, const int rows, const int cols) {
    generateZeroArray(rows, cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        this->at(i, j) = *(a + i*rows + j);
      }
    }
  }
  // ___________________________________________________________________________
  template <class T>
  void Matrix<T>::swap(Matrix& m) {
    // swap all the members  with m
    std::swap(_data, m._data);
    std::swap(_rows, m._rows);
    std::swap(_cols, m._cols);
  }
  // ___________________________________________________________________________
  template <class T>
  Matrix<T>::~Matrix() {
    delete [] _data;
  }
  // ___________________________________________________________________________
  template class Matrix<float>;
  template class Matrix<int>;
}

