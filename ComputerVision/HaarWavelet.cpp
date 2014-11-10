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
  CMatrix<float> HaarWavelet::decompose(const CMatrix<float>& img,
                                        const Shrinkage& sh,
                                        const int level) const {
    CMatrix<float> result(img.xSize(), img.ySize(), 0);
    decompose(img, sh, result);
    CMatrix<float> resultCut(result);
    for (int i = 1; i < level; i++) {
      result.cut(resultCut, 0, 0, result.xSize() / pow(2, i) - 1,
                 result.ySize() / pow(2, i) - 1);
      decompose(resultCut, sh, result);
    }
    return result;
  }
  // ___________________________________________________________________________
  void HaarWavelet::decompose(const CMatrix<float>& img, const Shrinkage& sh,
                              const CMatrix<float>& result) const {
    for (int y = 0; y < img.ySize(); y++) {
      for (int x = 0; x < img.xSize(); x++) {
        if (2 * x + 1 < img.xSize() && 2 * y + 1 < img.ySize()) {
          float cc = img(2*x, 2*y);
          float ch = img(2*x+1, 2*y);
          float cv = img(2*x, 2*y+1);
          float cd = img(2*x+1, 2*y+1);
          result(x, y) = 0.25 * (cc + ch + cv + cd);
          result(img.xSize() / 2 + x, y) = sh.shrinkValue(0.25 * (cc - ch +
                                                                  cv - cd));
          result(x, img.ySize() / 2 + y) = sh.shrinkValue(0.25 * (cc + ch -
                                                                  cv - cd));
          result(img.xSize() / 2 + x, img.ySize() / 2 + y) = sh.shrinkValue(
                                                  0.25 * (cc - ch - cv + cd));
        }
      }
    }
  }
  // ___________________________________________________________________________
  CMatrix<float> HaarWavelet::synthesize(const CMatrix<float>& img,
                                         const int level) const {
    CMatrix<float> result(img.xSize(), img.ySize(), 0);
    synthesize(img, result, result.xSize() / pow(2, (level-1)),
                            result.ySize() / pow(2, (level-1)));

    for (int i = 1; i < level; i++) {
      for (int x = 0; x < (result.xSize() / pow(2, (level-(i-1)-1))); x++) {
        for (int y = 0; y < (result.ySize() / pow(2, (level-(i-1)-1))); y++) {
          img(x, y) = result(x, y);
        }
      }
      synthesize(img, result, result.xSize() / pow(2, (level-i-1)),
                      result.ySize() / pow(2, (level-i-1)));
    }
    return result;
  }

  void HaarWavelet::synthesize(const CMatrix<float>& img,
                                         const CMatrix<float>& result,
                                         const int xSize,
                                         const int ySize) const {
    for (int y = 0; y < ySize; y++) {
      for (int x = 0; x < xSize; x++) {
        if (2 * x + 1 < xSize && 2 * y + 1 < ySize) {
          float c = img(x, y);
          float dh = img(xSize / 2 + x, y);
          float dv = img(x, ySize / 2 + y);
          float dd = img(xSize / 2 + x, ySize / 2 + y);
          result(2*x, 2*y) = (c + dh + dv + dd);
          result(2*x+1, 2*y) = (c - dh + dv - dd);
          result(2*x, 2*y+1) = (c + dh - dv - dd);
          result(2*x+1, 2*y+1) = (c - dh - dv + dd);
        }
      }
    }
  }
}

