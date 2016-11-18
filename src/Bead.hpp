#ifndef Bead_hpp
#define Bead_hpp

#include <stdio.h>
#include <ostream>
#include "Color.cpp"

/**
 * Class which represents a bead.
 */

class Bead {
public:

    /**
     * Constructor, takes in Color enum.
     */
    Bead(Color c);
    Color color;
    
    /**
     * Overload operator to print.
     */
    friend std::ostream& operator<<(std::ostream &strm, const Bead &b) {
        std::string message = "";
        
        switch(b.color) {
            case WHITE:
                message = "W";
                break;
            case RED:
                message = "R";
                break;
            default:
                message = "*";
        }
        
        return strm << message;
    }
};

#endif
/* Bead_hpp */
