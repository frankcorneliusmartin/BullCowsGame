//
//  FIsogram.hpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#pragma once
#include <string>
#include <iostream>

enum class EIsogramStatus{
    OK,
    Not_Isogram
};

class FIsogram{

    public:
    
        // constructor
        FIsogram(std::string isogram = "");
    
        // getters
        std::string getIsogram() const;
        EIsogramStatus isValid() const;
        size_t length() const;
    
        // setters
        void setIsogram(std::string isogram);
    
        // operators
        char operator[] (const int index) const;
        FIsogram operator=(std::string isogram);
        bool operator==(FIsogram isogram) const;
        friend std::ostream& operator<<(std::ostream& os, const FIsogram isogram);
    
    protected:
    
        std::string isogram;
    
    
    
};
