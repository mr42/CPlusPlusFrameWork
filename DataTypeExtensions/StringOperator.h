// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#ifndef DATATYPEEXTENSIONS_STRINGOPERATOR_H_
#define DATATYPEEXTENSIONS_STRINGOPERATOR_H_

#include <string>

using std::string;

namespace DataTypesExtensions {
  class StringOperator {
    public:
    // All the characters of the given string are converted to to lower case.
    void toLowerCase(string * s) const;
  };
}

#endif  // DATATYPEEXTENSIONS_STRINGOPERATOR_H_

