// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include <string>
#include "./String.h"

// _____________________________________________________________________________
TEST(StringTest, toLowerCase) {
  String s;
  string a = "klein";
  string b = "GROSS";
  string c = "mIx";
  ASSERT_EQ("klein", s.toLowerCase(a));
  ASSERT_EQ("gross",  s.toLowerCase(b));
  ASSERT_EQ("mix", s.toLowerCase(c));
}
