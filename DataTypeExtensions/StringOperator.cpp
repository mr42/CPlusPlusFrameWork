// Copyright 2013, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Michael Rudolph <michael30.rudolph@gmx.de>

#include <string>
#include "./StringOperator.h"

namespace DataTypesExtensions {
  // _____________________________________________________________________________
  void StringOperator::toLowerCase(std::string * s) const {
    for (size_t i = 0; i < s->length(); i++) {
      s->at(i) = std::tolower(s->at(i));
    }
  }
  // _____________________________________________________________________________
  void StringOperator::toUpperCase(std::string * s) const {
    for (size_t i = 0; i < s->length(); i++) {
      s->at(i) = std::toupper(s->at(i));
    }
  }
}
