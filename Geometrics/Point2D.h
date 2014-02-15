// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#ifndef GEOMETRICS_POINT2D_H_
#define GEOMETRICS_POINT2D_H_

namespace Geometrics {
  template<class T>
  class Point2D {
    public:
    Point2D(const T& x, const T& y) {
      _x = x;
      _y = y;
    }
    // Two Points are equal if both the x and the y
    // coordinate are the same.
    bool operator==(const Point2D p) {
      return this->_x == p._x && this->_y == p._y;
    }

    // Two Points aren't equal if the x and the y
    // coordinate is not the same.
    bool operator!=(const Point2D& p) {
      return this->_x != p._x || this->_y != p._y;
    }
    // Addition of two points.
    const Point2D operator+(const Point2D& p) {
      return Point2D(this->_x + p._x, this->_y + p._y);
    }

    // Substraction of two points.
    const Point2D operator-(const Point2D& p) {
      return Point2D(this->_x - p._x, this->_y - p._y);
    }

    T _x;
    T _y;
  };
}

#endif  // GEOMETRICS_POINT2D_H_

