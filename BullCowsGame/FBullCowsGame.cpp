//
//  FBullCowsGame.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include "FBullCowsGame.hpp"
#include "FIsogram.hpp"
#include "FGeuss.hpp"
#include <iostream>
#include <string>

FBullCowsGame::FBullCowsGame(int wordLength, int turns){
    this->reset(wordLength, turns);
}

void FBullCowsGame::reset(int wordLength, int turns){
    this->setNewIsogram(wordLength);
    this->geusses.clear();
    this->turns = turns;
    this->turn = 1;
    this->printIntoduction();
}

bool FBullCowsGame::UserPlayAgain(){
    std::string response;
    this->printAskUserToPlayAgain();
    std::getline(std::cin,response);
    this->reset((int)this->isogram.length(),this->turns);//maybe not the best place
    return (response[0] == 'y' || response[0] == 'Y');
}

int FBullCowsGame::UserGeuss(){
    
    this->printTurnMessage();
    
    // Get User Geuss
    this->turn++;
    FGeuss geuss;

    // Check if it is a valid Geuss
    while(!geuss.isValid(this->isogram.length())){
        this->printValidConditions();
        geuss.getUserGeuss();
    }

    // Store the Geuss
    geusses.push_back(geuss);
    
    // Check if the user has won or lost
    if(geuss == this->isogram){
        this->printWinMessage();
        return 0;
    }else if(this->turn == this->turns){
        this->printLostMessage();
        return 0;
    }
    
    // keep playing
    return 1;
}

// Prints

void FBullCowsGame::setNewIsogram(int wordLength){
    this->isogram = "ISOGRAM";
}

void FBullCowsGame::printIntoduction(){
    std::cout << "Welcome to this Bull and Cows game!" << std::endl;
    this->printValidConditions();
    std::cout << std::endl;
}

void FBullCowsGame::printValidConditions(){
    std::cout << "That's not a valid Geuss." << std::endl;
    std::cout << "We are looking for an isogram of " << this->isogram.length() << " letters!" << std::endl;
}

void FBullCowsGame::printAskUserToPlayAgain(){
    std::cout << "Do you want to play again? (y/n) ";
}

void FBullCowsGame::printWinMessage(){
    std::cout << "You Win!" << std::endl;   
}

void FBullCowsGame::printLostMessage(){
    std::cout << "You Lose!" << std::endl;   
}

void FBullCowsGame::printTurnMessage(){
    std::cout << "---------------------------------" << std::endl;
    std::cout << "TURN : " << this->turn << " of " << this->turns << std::endl;;
    this->printBullsAndCows();
    std::cout << std::endl;
}

void FBullCowsGame::printBullsAndCows(){
    
    size_t numberOfGeusses = this->geusses.size();
    
    for(int i = 0; i < numberOfGeusses; i++)
        this->geusses[i].printBullsAndCows(this->isogram.isogram);
        
    
}
