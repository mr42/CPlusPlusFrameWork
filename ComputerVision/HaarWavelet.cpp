/**
 * @file    HaarWavelet.cpp
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
 * The HaarWavelet.cpp desc.
 */

#include "HaarWavelet.h"
#include "Comparer.h"

namespace ComputerVision {
  HaarWavelet::HaarWavelet() {
  }

  HaarWavelet::HaarWavelet(const HaarWavelet& orig) {
  }

  HaarWavelet::~HaarWavelet() {
  }

  // ___________________________________________________________________________
  CMatrix<float> HaarWavelet::decompose(CMatrix<float> img,
                                        const int level) const {
    CMatrix<float> result(img.xSize(), img.ySize(), 0);
    decompose(img, result);
    for (int i = 1; i < level; i++) {
      result.cut(img, 0, 0, result.xSize() / (2*i) - 1,
                 result.ySize() / (2*i) - 1);
      decompose(img, result);
    }
    return result;
  }
  // ___________________________________________________________________________
  void HaarWavelet::decompose(const CMatrix<float>& img,
                              const CMatrix<float>& result) const {
    for (int y = 0; y < img.ySize(); y++) {
      for (int x = 0; x < img.xSize(); x++) {
        if (2 * x + 1 < img.xSize() && 2 * y + 1 < img.ySize()) {
          float cc = img(2*x, 2*y);
          float ch = img(2*x+1, 2*y);
          float cv = img(2*x, 2*y+1);
          float cd = img(2*x+1, 2*y+1);
          result(x, y) = 0.25 * (cc + ch + cv + cd);
          result(img.xSize() / 2 + x, y) = 0.25 * (cc - ch + cv - cd);
          result(x, img.ySize() / 2 + y) = 0.25 * (cc + ch - cv - cd);
          result(img.xSize() / 2 + x, img.ySize() / 2 + y) = 0.25 *
                                                            (cc - ch - cv + cd);
        }
      }
    }
  }
  
}

