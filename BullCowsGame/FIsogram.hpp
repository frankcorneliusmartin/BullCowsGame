//
//  FGeuss.hpp
//  BullCowsGame
//
//  Created by Frank Martin on 06/05/2017.
//  Copyright © 2017 Frank Martin. All rights reserved.
//

#pragma once
#include <string>
#include <iostream>

class FIsogram{

    public:
    
        FIsogram(std::string isogram = "");
    
        bool isValid() const; // TODO : no argument length should be required
    
        void setIsogram(std::string isogram);
        size_t length() const;
        std::string getIsogram() const;
        FIsogram operator=(std::string isogram);
        bool operator==(FIsogram isogram);
        friend std::ostream& operator<<(std::ostream& os, const FIsogram isogram);
    
    protected:
    
        std::string isogram;
    
    
    
};
