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

using int32 = int;

constexpr int WORD_LENGTH = 7;
constexpr int TURNS = 10;

void PlayGame();


int main() {
    PlayGame();
    return 0;
}

void PlayGame(){
    
    FBullCowsGame Game(WORD_LENGTH, TURNS);
    bool playing = true;
    do{
        
        if(!Game.UserGeuss())
            playing = Game.UserPlayAgain();

    }while(playing);
}

