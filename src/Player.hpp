//
//  Player.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-29.
//  Copyright © 2016 Fahad. All rights reserved.
//

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
    friend bool operator==(const Player& a1, const Player& a2);
};

#endif /* Player_hpp */
