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
    /**
     * @brief writeToFile():
     * writes given pattern to given file
     * 
     * @param filename 
     * @param patterns 
     */
    void writeToFile(const std::string& filename, std::vector<PatternCall> patterns);
    /**
     * @brief readFromFile()
     * read patterns from given file and returns them in vector of patterns
     * 
     * @param filename 
     * @return std::vector<PatternCall> 
     */
    std::vector<PatternCall> readFromFile(const std::string& filename);
};
#endif /* fileHandler_hpp */
