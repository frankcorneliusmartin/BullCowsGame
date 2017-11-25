//
//  main.cpp
//  BullCowsGame
//
//  Created by Frank Martin on 02/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include <iostream>
#include <string>

#include "FBullCowsGame.hpp"



std::string getUserGeuss();
void PrintInto();
void PlayGame();
bool AskToPlayAgain();

constexpr int WORD_LENGTH = 5;

int main() {
    PrintInto();
    do{
        PlayGame();
    }while(AskToPlayAgain());
    return 0;
}

void PrintInto(){
    std::cout << "Welcome to this shithole!" << std::endl;
    std::cout << "Can you geuss the key of " << WORD_LENGTH << " letters?" << std::endl << std::endl;
}

void PlayGame(){
    
    FBullCowsGame BCGame(5,10);
    std::string geuss;
    
    do{
        
        bool validQ = false;
        
        // Retrieve valid guess from the user
        do{
            geuss = getUserGeuss();
            validQ = BCGame.checkGeussValidity(geuss);
            if(!validQ){
                std::cout << geuss << "is not a valid geuss" << "\n";
                std::cout << "we are looking for a word having " << BCGame.getWordLength() << " charaters \n";
            }
        }while(!validQ);
        
        // Check if user has won
        if(BCGame.isGameWon(geuss)){
            std::cout << "Yaj! " << geuss << " is the right key!" << "\n";
            return;
        }else{
            std::cout << "That's not right: " << geuss << std::endl;
            std::cout << "Try " << BCGame.getCurrentTry() << std::endl;
            std::cout << std::endl;
        }
        
    }while(BCGame.hasTurns());
    
    std::cout << "You LOSE!" << "\n";
    
}

std::string getUserGeuss(){
    std::string geuss;
    std::cout << "Enter your geuss: ";
    std::getline(std::cin, geuss);
    return geuss;
}

bool AskToPlayAgain(){
    std::cout << "Do you want to play this again?: ";
    std::string response;
    std::getline(std::cin,response);
    return (response[0] == 'y' || response[0] == 'Y');
}
