//
//  Peg.cpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-28.
//  Copyright © 2016 Fahad. All rights reserved.
//

#include <iostream>

#include "Peg.hpp"

bool Peg::isFull() {
    return this->beads.size() == 3;
}

void Peg::addBead(Bead b) {
    if (!isFull()) {
        this->beads.push_back(b);
    } else {
        //TODO: Throw better error.
        //throw std::runtime_error("This peg is full");
        return;
    }
}

Bead Peg::getBeadAtLevel(int l) {
    try {
        Bead currBead = this->beads.at(l);
        return currBead;
    } catch (const std::out_of_range& oor) {
        return Bead(EMPTY);
    }
}

void Peg::printBeadAtLevel(int l) {
    try {
        Bead currBead = this->beads.at(l);
        if (currBead.color == RED || currBead.color == WHITE) {
            std::cout << currBead << " ";
        }
        
    } catch (const std::out_of_range& oor) {
        std::cout << "* ";
    }
}
