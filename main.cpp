/**
 * @file main.cpp
 * @author Hazem Elshaer
 * @brief 
 * @version 0.1
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include "patternHandler.hpp"

int main(int argc, const char * argv[]) {
    PatternHandler pH;
    PatternCall myPattern1{66,"newPattern1","src/patterns/Functional.pat",false};
    PatternCall myPattern2{16,"newPattern2","src/patterns/Functional.pat",true};
    PatternCall myPattern3{99,"newPattern3","src/patterns/Functional.pat",false};
    pH.loadPatternsFromFile("/Users/hazem/Xcode/PatternHandler/example.txt");
    pH.addPattern(myPattern1);
    pH.addPattern(myPattern2);
    pH.addPattern(myPattern3);
    pH.addPattern(myPattern3);
    pH.addPattern(myPattern3);
    pH.displayAllSavedPatterns();
    pH.writeSavedPatternsToFile("/Users/hazem/Xcode/PatternHandler/example2.txt");
    std::string type;
    int idValue=99;
    std::string nameValue="yourPattern";
    std::string filePathValue="src/patterns/Functional.pat";
    bool calledValue = true;
    type="id";
    Utils::printPatterns(pH.searchPatterns(type, idValue));
    type="name";
    Utils::printPatterns(pH.searchPatterns(type, nameValue));
    type="filepath";
    Utils::printPatterns(pH.searchPatterns(type, filePathValue));
    type="calledflag";
    Utils::printPatterns(pH.searchPatterns(type, calledValue));
    return 0;
}
