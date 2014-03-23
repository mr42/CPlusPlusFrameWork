/**
 * @file    Point.h
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
 * The Point class describes an _dim dimensional point. The point is
 * stored as an array.
 */

#ifndef GEOMETRICS_POINT_H_
#define GEOMETRICS_POINT_H_

#include <assert.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <cstdarg>
#include <vector>

namespace Geometrics {
  /**
   * The Point class describes an _dim dimensional point. The point is
   * stored as an array.
   */
  template<class T = int>
  class Point {
    public:
    Point() {
      _dim = 0;
      _coordinates = new T[0];
    }
    /**
     * The first constructor.
     * 
     * @param dim The dimension of the Point
     * @param ... The coordinates of the Point given
     *            as dynamic parameter list.
     */
    Point(int dim, ...)
    {
      va_list coordinates;
      _dim = dim;
      va_start(coordinates, dim);
      _coordinates = new T[_dim];
      for (int i = 0; i < _dim; i++) {
        _coordinates[i] = va_arg(coordinates, T);
      }

      va_end(coordinates);
    }

    /**
     * Make a deep copy of the given Point.
     * @param orig The original point, which should be copied.
     */
    Point(const Point& orig) {
      _dim = orig._dim;
      _coordinates = new T[_dim];
      for (int i = 0; i < orig._dim; i++)
        _coordinates[i] = orig._coordinates[i];
    }

    /**
     * 
     * The second constructor
     * 
     * @param dim The dimension of the Point.
     * @param value All coordinates are set
     *              to that value.
     */
    Point(const int dim, const T value)
    {
      _dim = dim;
      _coordinates = new T[_dim];
      for (int i = 0; i < dim; i++)
        _coordinates[i] = value;
    }

    /**
     * The destructor, which deletes the array, storing
     * the coordinates.
     */
    virtual ~Point()
    {
      delete [] _coordinates;
    }

    /**
     * Return the dimension of the Point
     * @return The dimension of the Point.
     */
    const int& getDim() {
      return _dim;
    }

    /**
     * 
     * The Point p is assigned to this, by swapping all the members of this and
     * the deep copy of p.
     * 
     * @param p The point right to the =. It's wanted,
     *          that p is passed by value.
     * @return This, with the members' values of p.
     */
    Point& operator= (Point p)
    {
      // swap this with other
      swap(p);
      // by convention, always return *this
      return *this;
      // note: p is destroyed, releasing the memory
    }

    /**
     * 
     * Overloading the == operator.
     * 
     * @param p The other Point.
     * @return True, if all the coordinates of both Points
     *         are the same.
     */
    bool operator==(const Point& p)
    {
      if (this->_dim != p._dim)  return false;
      for (int i = 0; i < this->_dim; i++) {
        if (this->_coordinates[i] != p._coordinates[i])
          return false;
      }
      return true;
    }
    /**
     * Overloading the != operator.
     * 
     * @param p The other Point.
     * @return True, if not all the coordinates of both
     *         Points are equal.
     */
    bool operator!=(const Point& p)
    {
      if (this->_dim != p._dim)  return true;
      for (int i = 0; i < this->_dim; i++) {
        if (this->_coordinates[i] != p._coordinates[i])
          return true;
      }
      return false;
    }

    /**
     * Overloading the + operator. Add two Points p1 and
     * p2. Throw an assertion, if the dimension of the
     * Points are not the same.
     *
     * @param p The other Point.
     * @return Point The Point(p3), where for all coordinates i, it holds:
     *               p3[i] = p1[i] + p2[i].
     */
    const Point operator+(const Point& p)
    {
      assert(this->_dim == p._dim);
      Point result(p._dim, 0);
      for (int i = 0; i < p._dim; i++)
        result._coordinates[i] = this->_coordinates[i] +
                                p._coordinates[i];
      return result;
    }

    /**
     * 
     * Overloading the += operator. Add the Point p to
     * the Point, standing before the += operator.
     * Throw an assertion, if the dimension of the
     * Points are not the same.
     * 
     * @param p The other Point.
     * @return The modified Point, standing before the += operator.
     */
    Point& operator+=(const Point& p)
    {
      assert(this->_dim == p._dim);
      for (int i = 0; i < p._dim; i++)
        this->_coordinates[i] = this->_coordinates[i] +
                                p._coordinates[i];
      return *this;
    }

    /**
     * Overloading the - operator. Add two Points p1 and
     * p2. Throw an assertion, if the dimension of the
     * vectors are not the same.
     *
     * @param p The other Point.
     * @return Point The Point(p3), where for all coordinate i, it holds:
     *               p3[i] = p1[i] - p2[i].
     */
    const Point operator-(const Point& p)
    {
      assert(this->_dim == p._dim);
      Point result(p._dim, 0);
      for (int i = 0; i < p._dim; i++)
        result._coordinates[i] = this->_coordinates[i] -
                                p._coordinates[i];
      return result;
    }

    /**
     * 
     * Overloading the -= operator. Subtract the Point p from
     * the Point, standing before the -= operator.
     * Throw an assertion, if the dimension of the
     * Points are not the same.
     * 
     * @param p The other Point.
     * @return The modified Point, standing before the -= operator.
     */
    Point& operator-=(const Point& p)
    {
      assert(this->_dim == p._dim);
      for (int i = 0; i < p._dim; i++)
        this->_coordinates[i] = this->_coordinates[i] -
                                p._coordinates[i];
      return *this;
    }

    /**
     * Overloading the * operator. Calculate the 
     * dot product of two Points(p1, p2).
     * Throw an assertion, if the dimension of the
     * vectors are not the same.
     *
     * @param p The other Point.
     * @return T The dot product of the two
     *           Points.
     */
    const T operator*(const Point& p)
    {
      assert(this->_dim == p._dim);
      T result = 0;
      for (int i = 0; i < p._dim; i++)
        result += this->_coordinates[i] * p._coordinates[i];
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

    /**
     * A function, doing th same like the [] operator. Non-Const variante.
     *
     * @param i is the coordinate index
     *
     * @return The value of the coordinate with the
     *         index i.
     *
     */
    T& at(const int& i)
    {
      return _coordinates[i];
    }

    /**
     * A function, doing th same like the [] operator. Const variante.
     * @param i is the coordinate index
     *
     * @return The value of the coordinate with the
     *         index i.
     *
     */
    const T& at(const int& i) const
    {
      return _coordinates[i];
    }

    private:
    /**
     * Swap all the members of p and this.
     * @param p The Point for the swapping
     */
    void swap(Point& p)
    {
      // swap all the members  with p
      std::swap(_coordinates, p._coordinates);
      std::swap(_dim, p._dim);
    }
    /**
     * The coordinates of the Point as array.
     */
    T* _coordinates;
    /**
     * The dimension of the Point.
     */
    int _dim;
  };
  /**
   * Specialication for float. This is needed
   * because the dynamic parameter list has
   * problems with float values. For that,
   * va_arg uses double and after that this
   * double value is converted to a float
   * value.
   */
  template<>
  class Point<float> {
    public:
    Point() {
      _dim = 0;
      _coordinates = new float[0];
    }
     /**
     * 
     * The first constructor.
     * 
     * @param dim The dimension of the Vector.
     * @param ... The coordinates of the Point as dynamic parameter list. 
     */
    Point(int dim, ...)
    {
      va_list coordinates;
      _dim = dim;
      va_start(coordinates, dim);
      _coordinates = new float[_dim];
      for (int i = 0; i < _dim; i++) {
        _coordinates[i] = static_cast<float>(va_arg(coordinates, double));
      }
      va_end(coordinates);
    }

    /**
     * Make a deep copy of the given Point.
     * @param orig The original point, which should be copied.
     */
    Point(const Point& orig) {
      _dim = orig._dim;
      _coordinates = new float[_dim];
      for (int i = 0; i < orig._dim; i++)
        _coordinates[i] = orig._coordinates[i];
    }

    /**
     * 
     * The second constructor
     * 
     * @param dim The dimension of the Point.
     * @param value All coordinates are set
     *              to that value.
     */
    Point(const int dim, const float value)
    {
      _dim = dim;
      _coordinates = new float[_dim];
      for (int i = 0; i < dim; i++)
        _coordinates[i] = value;
    }

    /**
     * The destructor, which deletes the array, storing
     * the coordinates.
     */
    virtual ~Point()
    {
      delete [] _coordinates;
    }

    /**
     * Return the dimension of the Point
     * @return The dimension of the Point.
     */
    const int& getDim() {
      return _dim;
    }

    /**
     * The Point p is assigned to this, by swapping all the members of this and
     * the deep copy of p.
     * 
     * @param p The point right to the =. It's wanted,
     *          that p is passed by value.
     * @return This, with the members' values of p.
     */
    Point& operator= (Point p)
    {
      // swap this with other
      swap(p);
      // by convention, always return *this
      return *this;
      // note: p is destroyed, releasing the memory
    }

    /**
     * 
     * Overloading the == operator.
     * 
     * @param p The other Point.
     * @return True, if all the coordinates of both Points
     *         are the same.
     */
    bool operator==(const Point& p)
    {
      if (this->_dim != p._dim)  return false;
      for (int i = 0; i < this->_dim; i++) {
        if (this->_coordinates[i] != p._coordinates[i])
          return false;
      }
      return true;
    }
    /**
     * Overloading the != operator.
     * 
     * @param p The other Point.
     * @return True, if not all the coordinates of both
     *         Points are equal.
     */
    bool operator!=(const Point& p)
    {
      if (this->_dim != p._dim)  return true;
      for (int i = 0; i < this->_dim; i++) {
        if (this->_coordinates[i] != p._coordinates[i])
          return true;
      }
      return false;
    }

    /**
     * Overloading the + operator. Add two Points p1 and
     * p2. Throw an assertion, if the dimension of the
     * Points are not the same.
     *
     * @param p The other Point.
     * @return Point The Point(p3), where for all coordinates i, it holds:
     *               p3[i] = p1[i] + p2[i].
     */
    const Point operator+(const Point& p)
    {
      assert(this->_dim == p._dim);
      Point result(p._dim, 0);
      for (int i = 0; i < p._dim; i++)
        result._coordinates[i] = this->_coordinates[i] +
                                p._coordinates[i];
      return result;
    }

    /**
     * 
     * Overloading the += operator. Add the Point p to
     * the Point, standing before the += operator.
     * Throw an assertion, if the dimension of the
     * Points are not the same.
     * 
     * @param p The other Point.
     * @return The modified Point, standing before the += operator.
     */
    Point& operator+=(const Point& p)
    {
      assert(this->_dim == p._dim);
      for (int i = 0; i < p._dim; i++)
        this->_coordinates[i] = this->_coordinates[i] +
                                p._coordinates[i];
      return *this;
    }

    /**
     * Overloading the - operator. Add two Points p1 and
     * p2. Throw an assertion, if the dimension of the
     * vectors are not the same.
     *
     * @param p The other Point.
     * @return Point The Point(p3), where for all coordinate i, it holds:
     *               p3[i] = p1[i] - p2[i].
     */
    const Point operator-(const Point& p)
    {
      assert(this->_dim == p._dim);
      Point result(p._dim, 0);
      for (int i = 0; i < p._dim; i++)
        result._coordinates[i] = this->_coordinates[i] -
                                p._coordinates[i];
      return result;
    }

    /**
     * 
     * Overloading the -= operator. Subtract the Point p from
     * the Point, standing before the -= operator.
     * Throw an assertion, if the dimension of the
     * Points are not the same.
     * 
     * @param p The other Point.
     * @return The modified Point, standing before the -= operator.
     */
    Point& operator-=(const Point& p)
    {
      assert(this->_dim == p._dim);
      for (int i = 0; i < p._dim; i++)
        this->_coordinates[i] = this->_coordinates[i] -
                                p._coordinates[i];
      return *this;
    }

    /**
     * Overloading the * operator. Calculate the 
     * dot product of two Points(p1, p2).
     * Throw an assertion, if the dimension of the
     * vectors are not the same.
     *
     * @param p The other Point.
     * @return T The dot product of the two
     *           Points.
     */
    const float operator*(const Point& p)
    {
      assert(this->_dim == p._dim);
      float result = 0;
      for (int i = 0; i < p._dim; i++)
        result += this->_coordinates[i] * p._coordinates[i];
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
    float& operator[](const int& i)
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
    const float& operator[](const int& i) const
    {
      return _coordinates[i];
    }

    /**
     * A function, doing th same like the [] operator. Non-Const variante.
     *
     * @param i is the coordinate index
     *
     * @return The value of the coordinate with the
     *         index i.
     *
     */
    float& at(const int& i)
    {
      return _coordinates[i];
    }

    /**
     * A function, doing th same like the [] operator. Const variante.
     * @param i is the coordinate index
     *
     * @return The value of the coordinate with the
     *         index i.
     *
     */
    const float& at(const int& i) const
    {
      return _coordinates[i];
    }

    private:
    /**
     * Swap all the members of p and this.
     * @param p The Point for the swapping
     */
    void swap(Point& p)
    {
      // swap all the members  with p
      std::swap(_coordinates, p._coordinates);
      std::swap(_dim, p._dim);
    }
    /**
     * The coordinates of the Point as array.
     */
    float* _coordinates;
    /**
     * The dimension of the Point.
     */
    int _dim;
  };
}

#endif  // GEOMETRICS_POINT_H_
