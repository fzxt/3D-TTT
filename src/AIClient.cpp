//
//  AIClient.cpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-15.
//  Copyright © 2016 Fahad. All rights reserved.
//

#include "AIClient.hpp"

AIClient::AIClient() {
}

void AIClient::getBestMove(GameBoard *gb) {
    AlphaBetaPruning::run(gb);
}

char AIClient::getRandomMove(GameBoard gb) {
    std::vector<char> availableMoves = gb.getAvailableMoves();
    int randomIndex = rand() % availableMoves.size();
    return availableMoves.at(randomIndex);
}
