//
//  patternMapper.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#include "patternMapper.hpp"

/**
 * @brief 
 * 
 * @param id 
 * @return PatternCall 
 */
PatternCall PatternMapper::getByID(int id){
    PatternCall resultPattern{0};
    if(!patterns.empty()){
        for(const auto& pattern:patterns){
            if(id==pattern.id){
                resultPattern = pattern;
            }
        }
    }
    else
        std::cout<<"Pattern memory is empty! Please load non empty file first"<<std::endl;
    return resultPattern;
}
/**
 * @brief 
 * 
 * @param name 
 * @return std::vector<PatternCall> 
 */
std::vector<PatternCall> PatternMapper::getByName(std::string name){
    std::vector<PatternCall> resultPatterns;
    if(!patterns.empty()){
        for (const auto& pattern : patterns) {
            if (pattern.name == name) {
                resultPatterns.push_back(pattern);
            }
        }
    }
    else
        std::cout<<"Pattern memory is empty! Please load non empty file first"<<std::endl;
    return resultPatterns;
}
/**
 * @brief 
 * 
 * @param filePath 
 * @return std::vector<PatternCall> 
 */
std::vector<PatternCall> PatternMapper::getByPath(std::string filePath){
    std::vector<PatternCall> resultPatterns;
    if(!patterns.empty()){
        for (const auto& pattern : patterns) {
            if (pattern.patternFile == filePath) {
                resultPatterns.push_back(pattern);
            }
        }
    }
    else
        std::cout<<"Pattern memory is empty! Please load non empty file first"<<std::endl;
    return resultPatterns;
}
/**
 * @brief 
 * 
 * @param flag 
 * @return std::vector<PatternCall> 
 */
std::vector<PatternCall> PatternMapper::getByFlag(bool flag){
    std::vector<PatternCall> resultPatterns;
    if(!patterns.empty()){
        for (const auto& pattern : patterns) {
            if (pattern.flag == flag) {
                resultPatterns.push_back(pattern);
            }
        }
    }
    else
        std::cout<<"Pattern memory is empty! Please load non empty file first"<<std::endl;
    return resultPatterns;
}
/**
 * @brief 
 * 
 * @param pattern 
 */
void PatternMapper::addToPatterns(PatternCall pattern){
    patterns.push_back(pattern);
}
/**
 * @brief 
 * 
 * @return std::vector<PatternCall> 
 */
std::vector<PatternCall> PatternMapper::getPatterns(){
    return patterns;
}
