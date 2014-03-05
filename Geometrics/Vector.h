/**
 * @file    Vector
 * @author  michael <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright 5. März 2014 University of Freiburg
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
 * description
 */

#ifndef GEOMETRICS_VECTOR_H_
#define GEOMETRICS_VECTOR_H_

#include <assert.h>
#include <gtest/gtest.h>
#include <cstdarg>
#include <vector>

namespace Geometrics {
  template<class T = int>
  class Vector {
    public:
    /**
     * 
     * The first constructor.
     * 
     * @param coordinates The coordinates of the Vector.
     * @param dimension The dimension of the Vector.
     */
    Vector(T coordinates[] , const int dimension)
    {
      _coordinates = coordinates;
      _dim = dimension;
      _delocate = false;
    }

    /**
     * 
     * The second constructor
     * 
     * @param dim The dimension of the Vector.
     * @param value All coordinates are set
     *        to that value.
     */
    Vector(const int dim, const T value)
    {
      _delocate = true;
      _dim = dim;
      _coordinates = new T[_dim];
      for (int i = 0; i < dim; i++)
        _coordinates[i] = value;
    }

    /**
     * The destructor, which deletes the array, storing
     * the coordinates.
     */
    virtual ~Vector()
    {
      if (_delocate) delete [] _coordinates;
    }

    /**
     * 
     * Overloading the == operator.
     * 
     * @param v The other Vector.
     * @return True, if all the coordinates of both Vectors
     *         are the same.
     */
    bool operator==(const Vector& v)
    {
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
     * @param v The other Vector.
     * @return True, if not all the coordinates of both
     *         Vector are equal.
     */
    bool operator!=(const Vector& v)
    {
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
     * @param v The other Vector.
     * @return Vector v3, where all coordinate i holds:
     *         v3[i] = v1[i] + v2[i].
     */
    const Vector operator+(const Vector& v)
    {
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
     * @param v The other Vector.
     * @return Vector v3, where all coordinate i holds:
     *         v3[i] = v1[i] - v2[i].
     */
    const Vector operator-(const Vector& v)
    {
      assert(this->_dim == v._dim);
      Vector result(v._dim, 0);
      for (int i = 0; i < v._dim; i++)
        result._coordinates[i] = this->_coordinates[i] -
                                v._coordinates[i];
      return result;
    }

    /**
     * Overloading the [] operator. Non-Const variante.
     *
     * @param i is the coordinate index
     *
     * @return The value of the coordinate with the
     *         index i.
     *
     */
    T& operator[](const int& i)
    {
      return _coordinates[i];
    }

    /**
     * Overloading the [] operator. Const variante.
     *@param i is the coordinate index
     *
     * @return The value of the coordinate with the
     *         index i.
     *
     */
    const T& operator[](const int& i) const
    {
      return _coordinates[i];
    }

    private:
    T* _coordinates;
    int _dim;
    bool _delocate;
  };
}

#endif  // GEOMETRICS_VECTOR_H_
