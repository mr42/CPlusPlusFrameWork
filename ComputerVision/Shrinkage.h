/**
 * @file    Shrinkage.h
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
 * The Shrinkage.h desc.
 */

#ifndef SHRINKAGE_H
#define	SHRINKAGE_H

#include<math.h>
#include"GeneralFunctions.h"

namespace ComputerVision {

enum Mode{NONE, HARD, SOFT};
  class Shrinkage {
  public:
    Shrinkage(const Mode mode, const float treshold);
    Shrinkage(const Shrinkage& orig);
    float shrinkValue(float val) const;
    virtual ~Shrinkage();
  private:
    float _treshold;
    Mode _mode;
  };
}

#endif	// SHRINKAGE_H

