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
    template <class T> std::vector<PatternCall> searchPatterns(std::string, T value);
};

template <class T>
std::vector<PatternCall> PatternHandler::searchPatterns(std::string searchType,T value){
    std::vector<PatternCall> resultPatterns;
    std::transform(searchType.begin(), searchType.end(), searchType.begin(),
        [](unsigned char c){ return std::tolower(c); });
    if(searchType=="id"||searchType=="calledflag"){
        if constexpr((std::is_same_v<T, int>)){
            std::cout<<"Searching for "<<searchType<<" with value "<<value<<" in saved Patterns"<<std::endl;
            PatternCall result;
            result=pM.getByID(value);
            resultPatterns.push_back(result);
        }
        else if constexpr((std::is_same_v<T, bool>)){
            std::cout<<"Searching for "<<searchType<<" with value "<<value<<" in saved Patterns"<<std::endl;
            resultPatterns=pM.getByFlag(value);
        }
        else{
            std::cout<<"Invalid search type and value combination!"<<std::endl;
        }
    }
    else
        std::cout<<"Invalid search type and value combination!"<<std::endl;
    return resultPatterns;
};
template <>
inline std::vector<PatternCall> PatternHandler::searchPatterns(std::string searchType,std::string value){
    std::vector<PatternCall> resultPatterns;
    std::transform(searchType.begin(), searchType.end(), searchType.begin(),
        [](unsigned char c){ return std::tolower(c); });
    if(searchType == "name"){
        std::cout<<"Searching for "<<searchType<<" with value "<<value<<" in saved Patterns"<<std::endl;
        resultPatterns=pM.getByName(value);
    }
    else if(searchType == "filepath"){
        std::cout<<"Searching for "<<searchType<<" with value "<<value<<" in saved Patterns"<<std::endl;
        resultPatterns=pM.getByPath(value);
    }
    else
        std::cout<<"Invalid search type and value combination!"<<std::endl;
    return resultPatterns;
};
#endif /* patternHandler_hpp */
