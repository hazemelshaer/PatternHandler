//
//  main.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//

#include <iostream>
#include "patternHandler.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
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
    pH.searchPatterns();
    pH.searchPatterns();
    pH.searchPatterns();
    pH.searchPatterns();
    return 0;
}
