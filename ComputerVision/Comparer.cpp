/**
 * @file    Comparer.cpp
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
 * The Comparer.cpp desc.
 */

#include "./Comparer.h"

namespace ComputerVision {

  Comparer::Comparer() {
  }

  Comparer::Comparer(const Comparer& orig) {
  }

  // ___________________________________________________________________________
  float Comparer::compareBool(const CMatrix<float>& img1,
                          const CMatrix<float>& img2) const {
    if (img1.xSize() != img2.xSize()) {
      std::cout << "Not the same x size" << std::endl;
      return false;
    }
    if (img1.ySize() != img2.ySize()) {
      std::cout << "Not the same y size" << std::endl;
      return false;
    }
    for (int x = 0; x < img1.xSize(); x++) {
      for (int y = 0; y < img1.ySize(); y++) {
        if (img1(x, y) != img2(x, y)) {
          std::cout << "xPos: " << x << std::endl;
          std::cout << "yPos: " << y << std::endl;
          std::cout << "value of img1: " << img1(x, y) << std::endl;
          std::cout << "value of img2: " << img2(x, y) << std::endl;
          return false;
        }
      }
    }
    return true;
  }

  // ___________________________________________________________________________
  CMatrix<float> Comparer::compare(const CMatrix<float>& img1,
                                   const CMatrix<float>& img2) const {
    CMatrix<float> result(img1.xSize(), img2.xSize(), 255);
    if (img1.xSize() != img2.xSize()) {
      std::cout << "Not the same x size" << std::endl;
      result.fill(0);
      return result;
    }
    if (img1.ySize() != img2.ySize()) {
      std::cout << "Not the same y size" << std::endl;
      result.fill(0);
      return result;
    }
    for (int x = 0; x < img1.xSize(); x++) {
      for (int y = 0; y < img1.ySize(); y++) {
        if (img1(x, y) != img2(x, y)) {
          result(x, y) = 0;
        }
      }
    }
    return result;
  }

  Comparer::~Comparer() {
  }
}

