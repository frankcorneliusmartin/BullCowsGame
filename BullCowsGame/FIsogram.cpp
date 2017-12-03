//
//  FIsogram.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include "FIsogram.hpp"

FIsogram FIsogram::operator=(std::string isogram){
    this->setIsogram(isogram);
    return (*this);
}

bool FIsogram::operator==(FIsogram isogram){
    return this->isogram == isogram.isogram;
}

void FIsogram::setIsogram(std::string isogram){
    
    for(int i = 0; i < isogram.length(); i++){
        isogram[i] = std::tolower(isogram[i]);
    }
    
    this->isogram = isogram;
};

std::string FIsogram::getIsogram(){
    return this->isogram;
}

std::ostream& operator<< (std::ostream& os, const FIsogram isogram){
    os << " --- " << isogram.isogram << " --- ";
    return os;
}

size_t FIsogram::length(){
    return this->isogram.length();
}

FIsogram::FIsogram(std::string isogram){
    this->setIsogram(isogram);
}

// check that each letter occurs once
bool FIsogram::isValid(size_t secretLength){
	
    // Check if the length is correct
    size_t wordLength = this->isogram.size();
    if(secretLength != wordLength)
        return false;
    
    // To Lowercase, ok we should do this earlier
    std::string l_isogram = this->isogram;
    for(int i = 0; i < wordLength; i++)
        this->isogram[i] = std::tolower(this->isogram[i]);
    
    std::sort(l_isogram.begin(), l_isogram.end());
    
    for (int i = 0; i < wordLength; i++)
    {
        if (l_isogram[i] == l_isogram[i + 1])
            return false;
    }
 	
    return true;

}
