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

void FGeuss::printBullsAndCows(std::string isogram){

    // Count bulls and Cows
    this->countBullsAndCows(isogram);
    
	// Print Something Readable 
	std::cout << this->isogram << "[";
	for(int i = 0; i < this->bulls; i++)
        std::cout << "X";

	for(int i = 0; i < this->cows; i++)
        std::cout << "O";
    
    for(int i = 0; i < this->miss; i++)
        std::cout << "_";

	std::cout << "]" << std::endl;

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

void FGeuss::countBullsAndCows(std::string isogram){

	// Initialize 
	this->cows = 0;
	this->bulls = 0;
    this->miss = 0;

	//count bulls and cows
	for(int i = 0; i < this->isogram.length(); i++){
		if(this->isogram[i] == isogram[i]){
			this->bulls++;
		}else if(this->isogram.find(isogram[i]) != std::string::npos){
			this->cows++;
        }else{
            this->miss++;
        }
	}

}

