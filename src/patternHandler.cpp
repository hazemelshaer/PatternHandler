//
//  patternHandler.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//
#include <iostream>
#include <sstream>
#include "patternHandler.hpp"

/**
 * @brief 
 * 
 * @param filename 
 */
void PatternHandler::loadPatternsFromFile(const std::string& filename){
    std::cout<<"Loading patterns from "<< filename<<" to memory"<<std::endl;
    for(const auto& pattern:fH.readFromFile(filename)){
        pM.addToPatterns(pattern);
    }
}
/**
 * @brief 
 * 
 * @param pattern 
 */
void PatternHandler::addPattern(PatternCall pattern){
    PatternCall resultPattern;
    resultPattern=pM.getByID(pattern.id);
    if(resultPattern.id==pattern.id)
        std::cout<<"A pattern with the id: "<<pattern.id<<" already exists!"<<std::endl;
    else
        pM.addToPatterns(pattern);
}
/**
 * @brief 
 * 
 * @param filename 
 */
void PatternHandler::writeSavedPatternsToFile(const std::string& filename){
    fH.writeToFile(filename,pM.getPatterns());
}
/**
 * @brief 
 * 
 */
void PatternHandler::displayAllSavedPatterns(){
    std::cout<<"Displaying all patterns in memory:"<<std::endl;
    for(const auto& pattern:pM.getPatterns()){
        std::cout<<pattern.id<<","<<pattern.name<<","<<pattern.patternFile<<","<<pattern.flag<<std::endl;
    }
}
