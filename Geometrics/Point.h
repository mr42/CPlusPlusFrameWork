// Copyright by Michale Rudolph, 2014
#ifndef GEOMETRICS_POINT_H_
#define GEOMETRICS_POINT_H_

namespace Geometrics {
  template <class T>
  class Point {
    public:
    Point(const T& x, const T& y) {
      _x = x;
      _y = y;
    }
    virtual ~Point() {}
    T _x;
    T _y;
  };
}

#endif  // GEOMETRICS_POINT_H_
