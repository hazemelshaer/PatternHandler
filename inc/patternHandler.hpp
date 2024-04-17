//
//  patternHandler.hpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#ifndef patternHandler_hpp
#define patternHandler_hpp

#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include "patternCall.hpp"
#include "fileHandler.hpp"
#include "patternMapper.hpp"
#include "Utils.hpp"

class PatternHandler{
    FileHandler fH;
    PatternMapper pM;
public:
    void loadPatternsFromFile(const std::string& filename);
    void addPattern(PatternCall pattern);
    void displayAllSavedPatterns();
    void writeSavedPatternsToFile(const std::string& filename);
    void searchPatterns();
};

#endif /* patternHandler_hpp */
