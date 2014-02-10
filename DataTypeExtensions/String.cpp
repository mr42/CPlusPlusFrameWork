// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <string>
#include "./String.h"

String::String() {
}

String::String(const String& orig) {
}

String::~String() {
}

// _____________________________________________________________________________
string String::toLowerCase(const string& s) const {
  const int length = s.length();
  string result = s;
  for (int i = 0; i < length; ++i) {
    result[i] = std::tolower(result[i]);
  }
  return result;
}
