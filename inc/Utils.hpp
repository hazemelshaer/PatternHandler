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
std::string isCalledToString(bool flag);
bool isCalledToBool(std::string);
void printPatterns(std::vector<PatternCall>);
};
#endif /* Utils_hpp */
