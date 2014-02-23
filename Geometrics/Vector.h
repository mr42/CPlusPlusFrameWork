// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#ifndef GEOMETRICS_VECTOR_H_
#define GEOMETRICS_VECTOR_H_

#include <assert.h>
#include <gtest/gtest.h>
#include <cstdarg>
#include <vector>

namespace Geometrics {
  template<class T>
  class Vector {
    public:
    /**
     * The constructor of Vector.
     *
     * @param dim should be the dimension of the vector
     *        and it is followed by a dynamic parameter
     *        list, where every parameter represants
     *        a coordinate.
     */
    Vector(int dim, ...) {
      va_list ap;
      va_start(ap, dim);
      _dim = dim;
      _coordinates = new T[_dim];
      for (int i = 0; i < _dim; i++) {
        _coordinates[i] = va_arg(ap, T);
      }
      va_end(ap);
    }
    /**
     * The constructor 2 of the Vector.
     *
     * @param Set the dimension of the Vector.
     * @param Set the value. All coordinates are set
     *        to that value.
     */
    Vector(const int dim, const T value) {
      _dim = dim;
      _coordinates = new T[static_cast<int>(_dim)];
      for (int i = 0; i < dim; i++)
        _coordinates[i] = value;
    }

    /**
     * The destructor, which deletes the array, storing
     * the coordinates.
     */
    virtual ~Vector() {
      delete [] _coordinates;
    }

    /**
     * Overloading the == operator.
     *
     * @return True, if all the coordinates of both Vectors
     *         are the same.
     */
    bool operator==(const Vector& v) {
      if (this->_dim != v._dim)  return false;
      for (int i = 0; i < this->_dim; i++) {
        if (this->_coordinates[i] != v._coordinates[i])
          return false;
      }
      return true;
    }
    /**
     * Overloading the != operator.
     *
     * @return True, if not all the coordinates of both
     *         Vector are equal.
     */
    bool operator!=(const Vector& v) {
      if (this->_dim != v._dim)  return true;
      for (int i = 0; i < this->_dim; i++) {
        if (this->_coordinates[i] != v._coordinates[i])
          return true;
      }
      return false;
    }
    /**
     * Overloading the + operator. Add two vector v1 and
     * v2. Throw an assertion, if the dimension of the
     * vectors are not the same.
     *
     * @return Vector v3, where all coordinate i holds:
     *         v3[i] = v1[i] + v2[i].
     */
    const Vector operator+(const Vector& v) {
      assert(this->_dim == v._dim);
      Vector result(v._dim, 0);
      for (int i = 0; i < v._dim; i++)
        result._coordinates[i] = this->_coordinates[i] +
                                v._coordinates[i];
      return result;
    }

    /**
     * Overloading the - operator. Add two vector v1 and
     * v2. Throw an assertion, if the dimension of the
     * vectors are not the same.
     *
     * @return Vector v3, where all coordinate i holds:
     *         v3[i] = v1[i] - v2[i].
     */
    const Vector operator-(const Vector& v) {
      assert(this->_dim == v._dim);
      Vector result(v._dim, 0);
      for (int i = 0; i < v._dim; i++)
        result._coordinates[i] = this->_coordinates[i] -
                                v._coordinates[i];
      return result;
    }
    T& operator[](const int& i) {
      return _coordinates[i];
    }

    const T& operator[](const int& i) const {
      return _coordinates[i];
    }
    private:
    T* _coordinates;
    int _dim;
  };
}

#endif  // GEOMETRICS_VECTOR_H_

