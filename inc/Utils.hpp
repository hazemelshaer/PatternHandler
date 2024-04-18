//
//  Utils.hpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 17.04.24.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <iostream>
#include "patternCall.hpp"

namespace Utils{
/**
 * @brief changes given bool to string
 * 
 * @param flag 
 * @return std::string 
 */
std::string isCalledToString(bool flag);
/**
 * @brief changes given string to bool
 * 
 * @return true 
 * @return false 
 */
bool isCalledToBool(std::string);
/**
 * @brief prints given vector of patterns to consol
 * 
 */
void printPatterns(std::vector<PatternCall>);
};
#endif /* Utils_hpp */
