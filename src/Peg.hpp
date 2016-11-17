//
//  Peg.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-28.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef Peg_hpp
#define Peg_hpp

#include <stdio.h>
#include <vector>

#include "Bead.hpp"

class Peg {
private:
    std::vector<Bead> beads;
public:
    void addBead(Bead b);
    Bead getBeadAtLevel(int l);
    void printBeadAtLevel(int l);
    bool isFull();
};

#endif /* Peg_hpp */
