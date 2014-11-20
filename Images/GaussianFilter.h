/* 
 * File:   GaussianFilter.h
 * Author: mich
 *
 * Created on November 4, 2014, 8:08 AM
 */

#include <math.h> 
#include <vector>
#include "Filter.h"

using std::vector;

#ifndef GAUSSIANFILTER_H
#define	GAUSSIANFILTER_H

class GaussianFilter : public Filter {
public:
  GaussianFilter();
  GaussianFilter(const GaussianFilter& orig);
  virtual ~GaussianFilter();
  virtual CMatrix<float> filter(const CMatrix<float>& img,
                                const float sigma=1) const;
private:
};

#endif	/* GAUSSIANFILTER_H */

