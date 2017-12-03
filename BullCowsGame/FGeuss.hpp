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

class FGeuss : public FIsogram{

    public:
        void getUserGeuss();
        void printBullsAndCows(std::string isogram);
        FGeuss();
    
    private:
        int bulls, cows, miss;
        void countBullsAndCows(std::string isogram);
    
};
