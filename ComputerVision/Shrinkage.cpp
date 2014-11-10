/**
 * @file    Shrinkage.cpp
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
 * The Shrinkage.cpp desc.
 */

#include "Shrinkage.h"

namespace ComputerVision {

  Shrinkage::Shrinkage(const Mode mode, const float treshold) {
    _mode = mode;
    _treshold = treshold;
  }

  Shrinkage::Shrinkage(const Shrinkage& orig) {
  }
  
  Shrinkage::~Shrinkage() {
  }
  
  float Shrinkage::shrinkValue(float val) const {
    if (_mode == HARD) {
      //val = GeneralFunctions::clipValue(val);
      if (fabs(val) <= _treshold) return 0;
    }
    if (_mode == SOFT) {
      //val = GeneralFunctions::clipValue(val);
      if (fabs(val) > _treshold)
        return GeneralFunctions::sign(val) * (fabs(val) - _treshold);
      return 0;  
    }
    return val;
  }
  


}