/**
 * @file    StringOperator.cpp
 * @author  michael <rudolphmichael42@gmail.com>
 * @version 1.0.0
 * 
 * @copyright Copyright 5. März 2014 University of Freiburg
 * 
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 * 
 * @section DESCRIPTION
 *
 * The StringOperator class provides a lot of useful functions, you often
 * need for strings.
 */

#include <string>
#include <vector>
#include "./StringOperator.h"

namespace DataTypesExtensions {
  // ___________________________________________________________________________
  void StringOperator::toLowerCase(std::string * s) const {
    for (size_t i = 0; i < s->length(); i++) {
      s->at(i) = std::tolower(s->at(i));
    }
  }
  // ___________________________________________________________________________
  void StringOperator::toUpperCase(std::string * s) const
  {
    for (size_t i = 0; i < s->length(); i++)
    {
      s->at(i) = std::toupper(s->at(i));
    }
  }
  // ___________________________________________________________________________
  vector<string> StringOperator::splitStringByBlank(
                                 const string& stringToSplit) const
  {
    vector<string> result;
    size_t i = 0;
    size_t start = 0;
    while (i < stringToSplit.size())
    {
      if (!isalnum(stringToSplit[i]))
      {
        if (i > start)
        {
          result.push_back(stringToSplit.substr(start, i - start));
        }
        start = i + 1;
      }
      ++i;
    }
    // Dont miss a word where there is no space/non-alnum in the end.
    if (i > start)
    {
      result.push_back(stringToSplit.substr(start, i - start));
    }
    return result;
  }
}
