/* 
 * File:   GaussianFilter.cpp
 * Author: mich
 * 
 * Created on November 4, 2014, 8:08 AM
 */

#include "GaussianFilter.h"

GaussianFilter::GaussianFilter() {
}

GaussianFilter::GaussianFilter(const GaussianFilter& orig) {
}

GaussianFilter::~GaussianFilter() {
}

CMatrix<float> GaussianFilter::filter(const CMatrix<float>& img,
                                      const float sigma) const {
  // create the kernel
  vector<float> kernel;
  kernel.resize(1 + sigma);
  float sum = 0;
  for (int i = 0; i <= sigma; i++) {
    kernel[i] = exp(-((i*i)/(float)(2*sigma*sigma)));
    if (i == 0)
      sum += kernel[i];
    else
      sum += kernel[i] * 2;
  }
  for (int i = 0; i <= sigma; i++) {
    kernel[i] = kernel[i] / sum;
  }
}
