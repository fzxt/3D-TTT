#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include <array>

#include "Peg.hpp"
#include "Player.hpp"

/**
 * Class that represents a GameBoard for 3D TTT.
 */

class GameBoard {
private:
    std::vector<Player> players;
    Player currTurn = Player(EMPTY);
    std::array<Peg, 8> board;
    int currTurnIdx;
public:
    GameBoard(std::vector<Player> playersPlaying);
    /**
     * Method to make a move, or to add a bead to the Peg.
     * @param b     Bead to add the board.
     * @param pegId Peg to add to.
     */
    void addBead(Bead b, char pegId);
    void printBoard();
    /**
     * Method to return the available moves
     * @return vector of avaialble pegs, by peg id (A-H)
     */
    std::vector<char> getAvailableMoves();
    /**
     * Sets the current turn.
     * @param p player to set turn to.
     */
    void setCurrentTurn(Player p);
    Player getCurrentTurn();
    /**
     * Returns peg
     * @param  n - which peg.
     * @return   Peg.
     */
    Peg at(int n);
    bool isFull();
};

#endif /* GameBoard_hpp */
