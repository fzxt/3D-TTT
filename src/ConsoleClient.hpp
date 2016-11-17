//
//  ConsoleClient.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-12.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef ConsoleClient_hpp
#define ConsoleClient_hpp

#include <stdio.h>
#include <iostream>

#include "Color.cpp"
#include "Player.hpp"

class ConsoleClient {
public:
    ConsoleClient();
    void run();
    Color getPlayerColor();
    Color getAIColor();
    bool promptExplanation();
    bool playAgain();
    void explainGame();
    char getPlayerMove();
    void printAIMove(char move);
private:
    Color playerColor;
    Color AIColor;
    bool prompt(std::string message);
    std::string to_lower(std::string str);
};


#endif /* ConsoleClient_hpp */
