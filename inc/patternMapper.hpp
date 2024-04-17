//
//  patternMapper.hpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#ifndef patternMapper_hpp
#define patternMapper_hpp

#include <stdio.h>
#include <iostream>
#include "patternCall.hpp"
#include "Utils.hpp"

class PatternMapper{
private:
    std::vector<PatternCall> patterns;
public:
    PatternCall getByID(int id);
    std::vector<PatternCall> getByName(std::string name);
    std::vector<PatternCall> getByPath(std::string filePath);
    std::vector<PatternCall> getByFlag(bool flag);
    void addToPatterns(PatternCall);
    std::vector<PatternCall> getPatterns();
};
#endif /* patternMapper_hpp */
