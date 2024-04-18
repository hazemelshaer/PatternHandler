//
//  Utils.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 17.04.24.
//

#include "Utils.hpp"

/**
 * @brief 
 * 
 * @param flag 
 * @return std::string 
 */
std::string Utils::isCalledToString(bool flag){
    if(flag){
        return "true";
    }
    return "false";
}
/**
 * @brief 
 * 
 * @param flag 
 * @return true 
 * @return false 
 */
bool Utils::isCalledToBool(std::string flag){
    std::transform(flag.begin(), flag.end(), flag.begin(),
        [](unsigned char c){ return std::tolower(c); });
    if(flag=="true"){
        return true;
    }
    return false;
}
/**
 * @brief 
 * 
 * @param patterns 
 */
void Utils::printPatterns(std::vector<PatternCall> patterns){
    for(const auto& pattern:patterns){
        std::cout<<pattern.id<<","<<pattern.name<<","<<pattern.patternFile<<","<<pattern.flag<<std::endl;
    }
}
