//
//  AIClient.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-15.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef AIClient_hpp
#define AIClient_hpp

#include <stdio.h>
#include "GameBoard.hpp"
#include "AlphaBetaPruning.cpp"

class AIClient {
public:
    AIClient();
    void getBestMove(GameBoard *gb);
    char getRandomMove(GameBoard gb);
};

#endif /* AIClient_hpp */
