/**
 * @file    GeneralFunctions.h
 * @author  mich <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright November 10, 2014 University of Freiburg
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
 * The GeneralFunctions.h desc.
 */

#ifndef GENERALFUNCTIONS_H
#define	GENERALFUNCTIONS_H

namespace ComputerVision {
  class GeneralFunctions {
  public:
    static float clipValue(const float val) {
      if (val > 255) return 255;
      if (val < 0) return 0;
      return val;
    }
    static float sign(const float val) {
      if (val > 0) return 1;
      if (val < 0) return -1;
      return 0;
    }
  private:
  };
}

#endif	// GENERALFUNCTIONS_H

