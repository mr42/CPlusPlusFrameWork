/**
 * @file    Circle.h
 * @author  michael <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright 23. März 2014 University of Freiburg
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

#ifndef GEOMETRICS_CIRCLE_H_
#define GEOMETRICS_CIRCLE_H_

#include "./Point.h"
using Geometrics::Point;

namespace Geometrics {
  template<class T = int>
  class Circle {
    public:
    /**
     * Creates an Circle with the given center and radius.
     * 
     * @param center The center of the Circle, represanted as Point.
     * @param radius  The radius of the Circle.
     */
    Circle(const Point<T>& center, const T radius) {
      _center = center;
      _radius = radius;
    }
    /**
     * A copy of the given Circle is generated.
     * @param orig The Circle, which should be copied.
     */
    Circle(const Circle& orig) {
      Circle(orig._center, orig._radius);
    }
    virtual ~Circle() {}

    T _radius;
    Point<T> _center;
  };
}

#endif  // GEOMETRICS_CIRCLE_H_

