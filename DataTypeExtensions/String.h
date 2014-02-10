// Copyright 10. Februar 2014 University of Freiburg
// Author michael <rudolphmichael42@gmail.com>

#ifndef DATATYPEEXTENSIONS_STRING_H_
#define DATATYPEEXTENSIONS_STRING_H_

#include <string>

using std::string;

class String {
  public:
  String();
  String(const String& orig);
  virtual ~String();
  string toLowerCase(const string& s) const;
  private:
};

#endif  // DATATYPEEXTENSIONS_STRING_H_

