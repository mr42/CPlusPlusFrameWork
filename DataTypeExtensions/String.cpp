// Copyright 2013, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Michael Rudolph <michael30.rudolph@gmx.de>

#include <string>
#include "./String.h"


// _____________________________________________________________________________
string String::toLowerCase(const std::string& str) const {
  const int length = str.length();
  string result = str;
  for (int i = 0; i < length; ++i) {
    result[i] = std::tolower(result[i]);
  }
  return result;
}
