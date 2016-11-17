//
//  GameBoard.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-28.
//  Copyright © 2016 Fahad. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include <array>

#include "Peg.hpp"
#include "Player.hpp"

class GameBoard {
private:
    std::vector<Player> players;
    Player currTurn = Player(EMPTY);
    std::array<Peg, 8> board;
    int currTurnIdx;
public:
    GameBoard(std::vector<Player> playersPlaying);
    void addBead(Bead b, char pegId);
    void printBoard();
    void scoreBoard();
    std::vector<char> getAvailableMoves();
    void setCurrentTurn(Player p);
    Player getCurrentTurn();
    Peg at(int n);
    bool isFull();
    void reset();
};

#endif /* GameBoard_hpp */
