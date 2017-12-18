//
//  main.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 02/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "FBullCowsGame.hpp"
#include "FIsogram.hpp"

using int32 = int;

// Game Settings
constexpr int WORD_LENGTH = 4;
constexpr int TURNS = 10;

// game object
FBullCowsGame Game;

void PlayGame();
bool UserPlayAgain();
void printIntoduction();
void printGameSummary();
FIsogram getValidUserGeuss();
FIsogram getUserGeuss();


int main() {
    
    do{
        Game.reset(WORD_LENGTH, TURNS);
        PlayGame();
    }while(UserPlayAgain());
    
    return 0;
}


void PlayGame(){
    
    
    // container for the user geuss
    FIsogram geuss;
    
    // print the intro
    printIntoduction();
    
    // for each turn
    while(Game.getCurrentTurn() != TURNS){
        
        // get valid user geuss
        geuss = getValidUserGeuss();
        Game.submitValidGeuss(geuss);
        
        // print summary
        printGameSummary();
        
        // check if the game has been won
        if(Game.isGameWon()){
            std::cout << "You Win! Congratulations!" << std::endl;
        }
        
    }
    
    // You lose!
    std::cout << "You Lose! Better luck next time!" << std::endl;
    
}

FIsogram getValidUserGeuss(){
    
    // initialize
    FIsogram geuss;
    EGeusValid status = EGeusValid::Invalid_Status;
    
    // as long as there is no valid geuss
    do{
        
        // get user input
        geuss = getUserGeuss();
    
        // check if the input is correct
        status = Game.checkGeussValidity(geuss);
        switch(status){
            case EGeusValid::Wrong_Length :
                std::cout << "Incorrect isogram Length, should be ";
                std::cout << Game.getHiddenWordLength() << " characters" << std::endl;
                break;
            case EGeusValid::Not_Isogram :
                std::cout << "This is not an isogram" << std::endl;
                break;
            default :
                NULL; // if valid geuss
        };
        
    }while(status != EGeusValid::OK);
    
    return geuss;
    
}

FIsogram getUserGeuss(){
    std::string buffer;
    std::cout << "Try " << Game.getCurrentTurn() << ". Enter your geuss: ";
    std::getline(std::cin, buffer);
    std::cout << std::endl;
    FIsogram geuss(buffer);
    return geuss;
}

bool UserPlayAgain(){
    
    // print message
    std::cout << "Do you want to play again? (y/n)";
    
    // get user response
    std::string response;
    std::getline(std::cin,response);
    
    return (response[0] == 'y' || response[0] == 'Y');
}

void printIntoduction() {
    std::cout << "Welcome to this Bulls and Cows game!" << std::endl;
    std::cout << "We are looking for an isogram of " << Game.getHiddenWordLength() << " letters." << std::endl;
    std::cout << "You have " << TURNS << " tries to find it." << std::endl;
    std::cout << std::endl;
}

void printGameSummary(){
    
    std::vector<BullsAndCowsCount> counts = Game.getBullsAndCowsOfAllGeusses();
    
    std::cout << "---------------------------------------" << std::endl;
    for(int i=0; i<counts.size();i++){
        std::cout <<"Guess: "<< counts[i].geuss;
        std::cout <<" | Bulls: " << counts[i].bulls;
        std::cout <<" | cows: " << counts[i].cows << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "\n\n";
    
}

