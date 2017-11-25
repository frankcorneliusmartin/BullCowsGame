//
//  FBullCowsGame.hpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#include <string>

class FBullCowsGame{

    public:
    
        // generates new secret and resets number of tries
        void reset();
    
        // Returns the maximum number of tries
        int getMaxTries();
    
        // Prints the Intoduction
        void printIntoduction();
    
        // Prints the requirements of the geuss
        void printValidConditions();
    
        // Checks if the geuss is correct
        bool isGameWon(std::string geuss);
    
        // Returns how many guesses the user has made
        int getCurrentTry();
    
    
        bool hasTurns();
    
        bool isValid(std::string geuss);
    
        // Constructor
        FBullCowsGame(int length, int maxTries);
    
        int currentTry;
    
    private:
    
        int maxTries;
        std::string secret;
    
        std::string generateSecret(int length);
    
};
