//
//  FBullCowsGame.hpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#pragma once
#include <string>
#include <vector>
#include "FGeuss.hpp"

class FBullCowsGame{

    public:
    
        FBullCowsGame(int wordLength, int turns);
        int UserGeuss();
        bool UserPlayAgain();
        void printBullsAndCows();
    
    protected:

        void reset(int wordLength, int turns);
        void setNewIsogram(int length);

    private:
    
        void printIntoduction();
        void printValidConditions();
        void printAskUserToPlayAgain() const;
        void printWinMessage() const;
        void printLostMessage() const;
        void printTurnMessage();
        
        int turn = 0; //current turn
        int turns = 10; // number of turns
        FIsogram isogram;
        std::vector<FGeuss> geusses;    
        
    
};
