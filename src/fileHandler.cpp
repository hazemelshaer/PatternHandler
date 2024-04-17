//
//  fileHandler.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#include "fileHandler.hpp"

void FileHandler::writeToFile(const std::string& filename, std::vector<PatternCall> patterns){
    std::ofstream out(filename);
    std::string called;
    for(const auto& pattern:patterns){
        out<<pattern.id<<","<<pattern.name<<","<<pattern.patternFile<<","<<Utils::isCalledToString(pattern.flag)<<std::endl;
    }
    out.close();
}

std::vector<PatternCall> FileHandler::readFromFile(const std::string& filename){
    std::ifstream file(filename);
    std::string line;
    std::vector<PatternCall> vPatterns;
    while (std::getline(file, line)) {
        std::cout<<line<<std::endl;
        std::istringstream iss(line);
        
        std::cout<<std::endl;
        std::string substring{};
        std::vector<std::string> substrings;
        PatternCall pattern;
        while (std::getline(iss, substring, ',')){
            substrings.push_back(substring);
        }
        pattern.flag =Utils::isCalledToBool(substrings.back());
        substrings.pop_back();
        pattern.patternFile= substrings.back();
        substrings.pop_back();
        pattern.name= substrings.back();
        substrings.pop_back();
        pattern.id=stoi(substrings.back());
        substrings.pop_back();
        vPatterns.push_back(pattern);
    }

    return vPatterns;
}
