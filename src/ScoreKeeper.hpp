//
//  ScoreBoard.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-11.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef ScoreKeeper_hpp
#define ScoreKeeper_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

#include "Player.hpp"
#include "GameBoard.hpp"

class ScoreKeeper {
private:
    static int calcScoreFullTower(GameBoard board, Player *p);
    static int calcScoreSingleLev(GameBoard board, Player *p);
    static int calcScoreMultipleLev(GameBoard board, Player *p);
public:
    static void calcScoreForPlayer(GameBoard board, Player *p);
    static void printWinner(GameBoard board, std::vector<Player> players);
};

#endif /* ScoreKeeper_hpp */
