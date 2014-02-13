// Copyright 2013, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Michael Rudolph <michael30.rudolph@gmx.de>

#include <string>
#include "./StringOperator.h"

namespace DataTypesExtensions {
  // _____________________________________________________________________________
  string StringOperator::toLowerCase(const std::string& s) const {
    const int length = s.length();
    string result = s;
    for (int i = 0; i < length; ++i) {
      result[i] = std::tolower(result[i]);
    }
    return result;
  }
}
