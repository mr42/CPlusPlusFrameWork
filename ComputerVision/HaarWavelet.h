/**
 * @file    HaarWavelet.h
 * @author  mich <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright November 9, 2014 University of Freiburg
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
 * The HaarWavelet.h desc.
 */

#ifndef HAARWAVELET_H
#define	HAARWAVELET_H

#include "CMatrix.h"

namespace ComputerVision {

  class HaarWavelet {
  public:
    HaarWavelet();

    // TODO: Implement the method for every level.
    /**
     * 
     * Decomposes a given image with the Haar wavelet.
     * 
     * @param img The image, which should be decomposed.
     * @param level
     * @return The decomposed image.
     */
    CMatrix<float> decompose(CMatrix<float> img,
                             const int level=2) const;
    HaarWavelet(const HaarWavelet& orig);
    virtual ~HaarWavelet();
  private:
    void decompose(const CMatrix<float>& img,
                   const CMatrix<float>& result) const;
  };
}

#endif	// HAARWAVELET_H

