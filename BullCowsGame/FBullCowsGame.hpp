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
#include "FIsogram.hpp"

enum class EGeusValid{
    Invalid_Status,
    OK,
    Wrong_Length,
    Not_Isogram
};

struct BullsAndCowsCount{
    FIsogram geuss;
    int bulls;
    int cows;
};

class FBullCowsGame{

    public:
        FBullCowsGame(int wordLength=0, int turns=0);
        void reset(int wordLength, int turns);
    
        // getters
        size_t getHiddenWordLength() const;
        int getCurrentTurn() const;
        EGeusValid checkGeussValidity(FIsogram) const;
        bool isGameWon() const;
        std::vector<BullsAndCowsCount> getBullsAndCowsOfAllGeusses() const;
    
        // setters
        void submitValidGeuss(FIsogram);
    
    
    protected:
        void setNewIsogram(int length); // TODO : cange to generateNewHiddenWord()

    private:
        int turn = 0; //current turn
        int turns = 10; // number of turns
        FIsogram isogram;
        std::vector<FIsogram> geusses;
    
};
