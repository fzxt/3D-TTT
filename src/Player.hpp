#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#include "Color.cpp"

class Player {
    int score;
    Color c;

public:
    Player(Color color);
    int getScore();
    void setScore(int val);
    Color getColor();
    void printColor();
    /**
     * Overload comparison.
     * Checks for same color.
     */
    friend bool operator==(const Player& a1, const Player& a2);
};

#endif /* Player_hpp */
