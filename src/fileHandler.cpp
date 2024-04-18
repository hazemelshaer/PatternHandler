//
//  fileHandler.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#include "fileHandler.hpp"

/**
 * @brief 
 * 
 * @param filename 
 * @param patterns 
 */
void FileHandler::writeToFile(const std::string& filename, std::vector<PatternCall> patterns){
    std::ofstream out(filename);
    std::string called;
    for(const auto& pattern:patterns){
        out<<pattern.id<<","<<pattern.name<<","<<pattern.patternFile<<","<<Utils::isCalledToString(pattern.flag)<<std::endl;
    }
    out.close();
}
/**
 * @brief 
 * 
 * @param filename 
 * @return std::vector<PatternCall> 
 */
std::vector<PatternCall> FileHandler::readFromFile(const std::string& filename){
    std::ifstream file(filename);
    std::string line;
    std::vector<PatternCall> vPatterns;
    std::cout<<"List of patterns found in file:"<<std::endl;
    while (std::getline(file, line)) {
        std::cout<<line<<std::endl;
        std::istringstream iss(line);
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
