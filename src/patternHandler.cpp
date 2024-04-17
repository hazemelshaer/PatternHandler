//
//  patternHandler.cpp
//  PatternHandler
//
//  Created by Hazem Elshaer on 13.04.24.
//
#include <iostream>
#include <sstream>
#include "patternHandler.hpp"

void PatternHandler::loadPatternsFromFile(const std::string& filename){
    for(const auto& pattern:fH.readFromFile(filename)){
        pM.addToPatterns(pattern);
    }
//    pM.patterns = fH.readFromFile(filename);
}
void PatternHandler::addPattern(PatternCall pattern){
    PatternCall resultPattern;
    resultPattern=pM.getByID(pattern.id);
    if(resultPattern.id==pattern.id)
        std::cout<<"A pattern with the id: "<<pattern.id<<" already exists!"<<std::endl;
    else
        pM.addToPatterns(pattern);
}

void PatternHandler::writeSavedPatternsToFile(const std::string& filename){
    fH.writeToFile(filename,pM.getPatterns());
}

void PatternHandler::searchPatterns(){
    int selection;
    std::cout<<"Enter search type:"<<std::endl;
    std::cout<<"1 -> by ID"<<std::endl<<"2 -> by Name"<<std::endl<<"3 -> by File Path"<<std::endl<<"4 -> by Called status"<<std::endl;
    std::cin>>selection;
    std::vector<PatternCall> resultPatterns;
    if(selection == 1){
        PatternCall result;
        int id=0;
        std::cout<<"Enter id number:"<<std::endl;
        std::cin>>id;
        result=pM.getByID(id);
        resultPatterns.push_back(result);
    }
    else if(selection==2){
        std::string name;
        std::cout<<"Enter Name:"<<std::endl;
        std::cin>>name;
        resultPatterns=pM.getByName(name);
    }
    else if(selection==3){
        std::string filePath;
        std::cout<<"Enter File Path"<<std::endl;
        std::cin>>filePath;
        resultPatterns=pM.getByPath(filePath);
    }
    else if(selection==4){
        std::string called;
        std::cout<<"Enter Called true or false:"<<std::endl;
        std::cin>>called;
        resultPatterns=pM.getByFlag(Utils::isCalledToBool(called));
    }
    else
        std::cout<<"wrong input try again"<<std::endl;
    for(const auto& pattern:resultPatterns){
        std::cout<<pattern.id<<","<<pattern.name<<","<<pattern.patternFile<<","<<pattern.flag<<std::endl;
    }
}

void PatternHandler::displayAllSavedPatterns(){
    for(const auto& pattern:pM.getPatterns()){
        std::cout<<pattern.id<<","<<pattern.name<<","<<pattern.patternFile<<","<<pattern.flag<<std::endl;
    }
}
