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

bool FIsogram::operator==(FIsogram isogram) const{
    return this->isogram == isogram.isogram;
}

char FIsogram::operator[] (const int index) const{
    return this->isogram[index];
}

void FIsogram::setIsogram(std::string isogram = ""){
    
    // to lowercase 
    for(int i = 0; i < isogram.length(); i++){
        isogram[i] = std::tolower(isogram[i]);
    }
    
    this->isogram = isogram;
};

std::string FIsogram::getIsogram() const{
    return this->isogram;
}

std::ostream& operator<< (std::ostream& os, const FIsogram isogram){
    os << "" << isogram.isogram << "";
    return os;
}

size_t FIsogram::length() const{
    return this->isogram.length();
}


FIsogram::FIsogram(std::string isogram){
    this->setIsogram(isogram);
}

// check that each letter occurs once
EIsogramStatus FIsogram::isValid() const{
	
    // make local copy for sorting
    std::string l_isogram = this->isogram;
    
    // sort
    std::sort(l_isogram.begin(), l_isogram.end());
    
    // check if duplicate letters are present
    for (int i = 0; i < this->isogram.size(); i++)
    {
        if (l_isogram[i] == l_isogram[i + 1])
            return EIsogramStatus::NOT_ISOGRAM;
    }
 	
    return EIsogramStatus::OK;

}
