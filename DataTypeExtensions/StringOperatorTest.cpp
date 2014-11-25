// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "./StringOperator.h"

using DataTypesExtensions::StringOperator;

// _____________________________________________________________________________
TEST(StringTest, splitStringByBlank) {
  StringOperator s;
  vector<string> result = s.splitStringByBlank(
          "I study at the University Freiburg");
  string expected[] = {"I", "study", "at", "the", "University", "Freiburg"};
  EXPECT_EQ(6, result.size());
  for (size_t i = 0; i < 6; i++) {
    EXPECT_EQ(expected[i], result[i]);
  }
  vector<string> result2 = s.splitStringByBlank("");
  EXPECT_EQ(0, result2.size());
}

// _____________________________________________________________________________
TEST(StringTest, toLowerCase) {
  StringOperator s;
  string a = "small";
  string b = "LARGE";
  string c = "mIx";
  s.toLowerCase(&a);
  s.toLowerCase(&b);
  s.toLowerCase(&c);
  EXPECT_EQ("small", a);
  EXPECT_EQ("large", b);
  EXPECT_EQ("mix", c);
}

// _____________________________________________________________________________
TEST(StringTest, toUpperCase) {
  StringOperator s;
  string a = "small";
  string b = "LARGE";
  string c = "mIx";
  s.toUpperCase(&a);
  s.toUpperCase(&b);
  s.toUpperCase(&c);
  EXPECT_EQ("SMALL", a);
  EXPECT_EQ("LARGE", b);
  EXPECT_EQ("MIX", c);
}
