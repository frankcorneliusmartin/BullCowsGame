//
//  FBullCowsGame.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "FIsogram.hpp"
#include "FBullCowsGame.hpp"

FBullCowsGame::FBullCowsGame(int wordLength, int turns){
    this->reset(wordLength, turns);
}

void FBullCowsGame::reset(int wordLength, int turns){
    this->setNewIsogram(wordLength);
    this->geusses.clear();
    this->turns = turns;
    this->turn = 1;
}

// getters

size_t FBullCowsGame::getHiddenWordLength() const{
    return this->isogram.length();
}

int FBullCowsGame::getCurrentTurn() const {
    return this->turn;
}

// Setters

void FBullCowsGame::setNewIsogram(int wordLength){
    
    // Initialization 
    std::string secret = "";
    char letter;
    
    // select random numbers
    for(int i = 0; i < wordLength; i++){
        
        // keep randomly selecting letters till unique letter is found
        do{
            letter = 'a' + std::rand()%26; // generate new letter
        }while(secret.find(letter) != std::string::npos);
        
        // Store unique letter
        secret+=letter;
    }
    
    // Set the objects value
    this->isogram = secret;
    return;
}

EGeusValid FBullCowsGame::checkGeussValidity(FIsogram geuss) const{
    
    // check if it is an isogram
    if(geuss.isValid() != EIsogramStatus::OK)
        return EGeusValid::Not_Isogram;
    
    // check the length
    if(geuss.length() != this->isogram.length())
        return EGeusValid::Wrong_Length;
    
    // otherwise is valid geuss
    return EGeusValid::OK;
    
}

// assuming the submitted geuss is valid
void FBullCowsGame::submitValidGeuss(FIsogram validGeuss) {
    
    // up the turn
    this->turn++;
    
    // append new geuss to the geuss list
    geusses.push_back(validGeuss);
}

// TODO: optimize
bool FBullCowsGame::isGameWon() const {
    
    // if one of the geusses contains the hidden word
    for(int i=0; i<geusses.size(); i++){
        if(this->geusses[i] == this->isogram)
            return true;
    }
    
    // otherwise return false
    return false;
}

// TODO: optimize
std::vector<BullsAndCowsCount> FBullCowsGame::getBullsAndCowsOfAllGeusses() const {
    
    // container for all the counts
    std::vector<BullsAndCowsCount> counts(geusses.size());
    size_t len = this->getHiddenWordLength(); // All word lengths are the same
    
    // for all valid geusses
    for(int i=0; i<geusses.size(); i++){
        
        counts[i].geuss = geusses[i].getIsogram();
        
        // for all geuss letters
        for(int j=0; j<len; j++){
            
            // for all hidden word letters
            for(int k=0; k<len; k++){
                
                if(this->geusses[i][j] == this->isogram[k]){
                    
                    if(k == j){
                        counts[i].bulls++;
                    }else{
                        counts[i].cows++;
                    }
                    
                }
            }
        }
    }
    return counts;
}


