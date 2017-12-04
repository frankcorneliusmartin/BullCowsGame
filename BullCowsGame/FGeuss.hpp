//
//  FGeuss.hpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#pragma once
#include <string>
#include "FIsogram.hpp"

// Initialized zero
struct FBullCowCount{
    int bulls = 0;
    int cows = 0;
};

class FGeuss : public FIsogram{

    public:
        void getUserGeuss();
        void printBullsAndCows(std::string);
        FGeuss();
        bool isValid();
    
    private:
        int bulls, cows;
        FBullCowCount countBullsAndCows(std::string);
    
};
