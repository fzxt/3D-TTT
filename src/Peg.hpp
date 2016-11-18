#ifndef Peg_hpp
#define Peg_hpp

#include <stdio.h>
#include <vector>

#include "Bead.hpp"

/**
 * Class that represents a peg.
 */

class Peg {
private:
    std::vector<Bead> beads;
public:
    /**
     * Method to add a bead to a peg.
     * @param b the bead you wish to add to the peg.
     */
    void addBead(Bead b);
    /**
     * Returns bead at level (from 0 - 2)
     * @param  l to level to access.
     * @return   beads.
     */
    Bead getBeadAtLevel(int l);
    void printBeadAtLevel(int l);
    bool isFull();
};

#endif /* Peg_hpp */
