//
//  FGeuss.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 30/11/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include "FGeuss.hpp"
#include <iostream>
#include <string>

constexpr int WORD_LENGTH = 4; // TODO : place this some where appropiate, or let the user set this

void FGeuss::printBullsAndCows(std::string isogram){
    
    // Count bulls and Cows
    FBullCowCount bullsAndCows = this->countBullsAndCows(isogram);
    
	// Print Something Readable 
	std::cout << this->getIsogram() << " [ ";
	for(int i = 0; i < bullsAndCows.bulls; i++)
        std::cout << "X";

	for(int i = 0; i < bullsAndCows.cows; i++)
        std::cout << "O";
    
	std::cout << " ] " << std::endl;

}

void FGeuss::getUserGeuss(){
    
    std::string buffer;
    
    std::cout << "Enter your geuss: ";
    std::getline(std::cin, buffer);
    
    this->setIsogram(buffer);

}

FGeuss::FGeuss(){
	this->getUserGeuss();
}

FBullCowCount FGeuss::countBullsAndCows(std::string isogram){

    // initialize
    FBullCowCount bullsAndCows;
    
	//count bulls and cows
	for(int i = 0; i < this->isogram.length(); i++){
		if(this->isogram[i] == isogram[i]){
            bullsAndCows.bulls++;
		}else if(this->isogram.find(isogram[i]) != std::string::npos){
            bullsAndCows.cows++;
        }
	}
    
    // return bulls and cows
    return bullsAndCows;

}

bool FGeuss::isValid(){
    
    // check if isogram conditions are met
    if(!FIsogram::isValid())
        return false;
    
    // check if the length is correct
    if(this->getIsogram().length() != WORD_LENGTH)
        return false;
    
    return true;
}
