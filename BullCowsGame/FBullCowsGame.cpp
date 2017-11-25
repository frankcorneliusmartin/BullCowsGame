//
//  FBullCowsGame.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include "FBullCowsGame.hpp"

FBullCowsGame::FBullCowsGame(int length, int tries){
    this->reset();
    this->maxTries = tries;
    //this->secret = this->generateSecret(length);
}

void FBullCowsGame::reset(){
    int l = (int) this->secret.length();
    this->secret = this->generateSecret(l);
    this->currentTry = 0;
    return;
}

int FBullCowsGame::getWordLength(){
    return (int) this->secret.length();
}

int FBullCowsGame::getMaxTries(){
    return this->maxTries;
}

int FBullCowsGame::getCurrentTry(){
    return this->currentTry;
}

bool FBullCowsGame::hasTurns(){
    return this->currentTry < this->maxTries;
}

bool FBullCowsGame::isGameWon(std::string geuss){
    return geuss == this->secret;
}

bool FBullCowsGame::checkGeussValidity(std::string geuss){
    return geuss.length() == this->secret.length();
}

std::string FBullCowsGame::generateSecret(int length){
    return "Henkie";
}
