//  Peg.cpp

#include <iostream>

#include "Peg.hpp"

bool Peg::isFull() {
    return this->beads.size() == 3;
}

void Peg::addBead(Bead b) {
    if (!isFull()) {
        this->beads.push_back(b);
    } else {
        throw std::runtime_error("This peg is full");
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
