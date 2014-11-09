/**
 * @file    Comparer.h
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
 * The Comparer.h desc.
 */

#ifndef COMPARER_H
#define	COMPARER_H

#include"CMatrix.h"

namespace ComputerVision {

  class Comparer {
  public:
    Comparer();
    Comparer(const Comparer& orig);
    /**
     * Compares two images and returns true if all pixels have the same value.
     * 
     * @param img1 The first image.
     * @param img2 The second image.
     * @return True, if all pixels of the two images are the same.
     */
    float compareBool(const CMatrix<float>& img1,
                      const CMatrix<float>& img2) const;
    /**
     * Compares two images and returns an image which shows the pixels which
     * have the same value in white and the pixels which differ in the value in
     * black.
     * 
     * @param img1 The first image.
     * @param img2 The second image.
     * @return Image where all pixels which are the same in both images are
     *         colored white and black otherwise.
     */
    CMatrix<float> compare(const CMatrix<float>& img1,
                           const CMatrix<float>& img2) const;

    virtual ~Comparer();
  private:

  };

}

#endif	// COMPARER_H

