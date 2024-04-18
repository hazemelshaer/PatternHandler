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
    /**
     * @brief Get the By I D object
     * 
     * @param id 
     * @return PatternCall 
     */
    PatternCall getByID(int id);
    /**
     * @brief Get the By Name object
     * 
     * @param name 
     * @return std::vector<PatternCall> 
     */
    std::vector<PatternCall> getByName(std::string name);
    /**
     * @brief Get the By Path object
     * 
     * @param filePath 
     * @return std::vector<PatternCall> 
     */
    std::vector<PatternCall> getByPath(std::string filePath);
    /**
     * @brief Get the By Flag object
     * 
     * @param flag 
     * @return std::vector<PatternCall> 
     */
    std::vector<PatternCall> getByFlag(bool flag);
    /**
     * @brief 
     * 
     */
    void addToPatterns(PatternCall);
    /**
     * @brief Get the Patterns object
     * 
     * @return std::vector<PatternCall> 
     */
    std::vector<PatternCall> getPatterns();
};
#endif /* patternMapper_hpp */
