#ifndef ScoreKeeper_hpp
#define ScoreKeeper_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

#include "Player.hpp"
#include "GameBoard.hpp"

/**
 * This class handles all the logic for calculating scores as well as
 * determining and displaying winners to the console.
 */

class ScoreKeeper {
private:
   /**
    * Checks for full towers of the same color.
    * @param  board the GameBoard.
    * @param  p     the relevant player.
    * @return       sum of full tower scores.
    */
    static int calcScoreFullTower(GameBoard board, Player *p);
    /**
     * Checks for 3 pegs in a row in x and y directions.
     * @param  board the GameBoard
     * @param  p     the relevant player.
     * @return       sum of horizontal and vertical scores.
     */
    static int calcScoreSingleLev(GameBoard board, Player *p);
    /**
     * Checks for scores of multiple levels (simply, diagonals).
     * @param  board the GameBoard
     * @param  p     the relevant player.
     * @return       Sum of diagonal scores.
     */
    static int calcScoreMultipleLev(GameBoard board, Player *p);
public:
   /**
    * Calculates and sets score for players.
    * @param board the GameBoard
    * @param p     the relevant players.
    */
    static void calcScoreForPlayer(GameBoard board, Player *p);
    /**
     * Checks and prints who won to the console.
     * @param board   the GameBoard
     * @param players the players who are playing the game.
     */
    static void printWinner(GameBoard board, std::vector<Player> players);
};

#endif /* ScoreKeeper_hpp */
