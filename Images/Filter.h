/* 
 * File:   Filter.h
 * Author: mich
 *
 * Created on November 4, 2014, 8:07 AM
 */

#ifndef FILTER_H
#define	FILTER_H

#include "CMatrix.h"

class Filter {
public:
  Filter();
  Filter(const Filter& orig);
  virtual ~Filter();
  virtual CMatrix<float> filter(const CMatrix<float>& img,
                                const float sigma=1) const=0;
protected:
  float mSigma;
private:
};

#endif	/* FILTER_H */

