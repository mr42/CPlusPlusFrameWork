// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include <string>
#include "./StringOperator.h"

using DataTypesExtensions::StringOperator;

// _____________________________________________________________________________
TEST(StringTest, toLowerCase) {
  StringOperator s;
  string a = "small";
  string b = "LARGE";
  string c = "mIx";
  s.toLowerCase(&a);
  s.toLowerCase(&b);
  s.toLowerCase(&c);
  ASSERT_EQ("small", a);
  ASSERT_EQ("large", b);
  ASSERT_EQ("mix", c);
}
