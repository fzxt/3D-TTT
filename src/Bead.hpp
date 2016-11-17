//
//  Bead.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-28.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef Bead_hpp
#define Bead_hpp

#include <stdio.h>
#include <ostream>
#include "Color.cpp"

class Bead {
public:
    Bead(Color c);
    Color color;
    
    friend std::ostream& operator<<(std::ostream &strm, const Bead &b) {
        std::string message = b.color == WHITE ? "W" : "R";
        return strm << message;
    }
};

#endif 
/* Bead_hpp */
