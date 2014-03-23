/**
 * @file    StringOperator.h
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

#ifndef DATATYPEEXTENSIONS_STRINGOPERATOR_H_
#define DATATYPEEXTENSIONS_STRINGOPERATOR_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace DataTypesExtensions {
  /**
   * The StringOperator class provides a lot of useful functions, you often
   * need for strings.
   */
  class StringOperator {
    public:
    /**
     * All the characters of the given string are converted to lower case.
     * @param s The string, whose letters should be converted to lower case
     */
    void toLowerCase(string * s) const;
    /**
     * All the characters of the given string are converted to to upper case.
     * @param s The string, whose letters should be converted to upper case
     */
    void toUpperCase(string * s) const;
    /**
     * Split a string by delimiter "blank" and return the generated
     * substrings as vector.
     * 
     * @param stringToSplit The string, which should be splited.
     * @return The generated substrings from stringToSplit.
     */
    vector<string> splitStringByBlank(const string& stringToSplit) const;
  };
}

#endif  // DATATYPEEXTENSIONS_STRINGOPERATOR_H_

