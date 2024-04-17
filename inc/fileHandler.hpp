//
//  fileHandler.hpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#ifndef fileHandler_hpp
#define fileHandler_hpp

#include <stdio.h>
#include <filesystem>
#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "patternCall.hpp"
#include "Utils.hpp"


class FileHandler{
public:
    void writeToFile(const std::string& filename, std::vector<PatternCall> patterns);
    std::vector<PatternCall> readFromFile(const std::string& filename);
};
#endif /* fileHandler_hpp */
