/**
 * @file    NoiseMeasurer.cpp
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
 * The NoiseMeasurer.cpp desc.
 */

#include "NoiseMeasurer.h"

namespace ComputerVision {

  NoiseMeasurer::NoiseMeasurer() {
  }

  NoiseMeasurer::NoiseMeasurer(const NoiseMeasurer& orig) {
  }

  NoiseMeasurer::~NoiseMeasurer() {
  }


  double NoiseMeasurer::computePSNR(const CMatrix<float>& original,
                     const CMatrix<float>& noise) const {
    double size = original.xSize()*original.ySize();
    double diff = original.max() - original.min();
    double sum = 0;
    // compute the sum
    for (int x = 0; x < original.xSize(); x++) {
      for (int y = 0; y < original.ySize(); y++) {
        sum += (original(x, y) - noise(x, y)) * (original(x, y) - noise(x, y));
      }
    }
    return 10 * log10((size * diff * diff) / sum);
  }

}