//
//  AlphaBetaPruning.hpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-13.
//  Copyright © 2016 Fahad. All rights reserved.
//

#include <stdio.h>
#include "Player.hpp"
#include "ScoreKeeper.hpp"
#include "GameBoard.hpp"

//So, none of this works :(
class AlphaBetaPruning {
public:
    static void run(GameBoard *gb) {
        alphaBetaPruning(gb->getCurrentTurn(), gb, __DBL_MIN__, __DBL_MAX__, 0);
    }
private:
    
    static int alphaBetaPruning(Player p, GameBoard *gb, double alpha, double beta, int currentPly) {
        if (currentPly++ == 6 || gb->isFull()) {
            ScoreKeeper::calcScoreForPlayer(*gb, &p);
            return p.getScore();
        }
        
        if (gb->getCurrentTurn() == p) {
            return getMax(p, gb, alpha, beta, currentPly);
        } else {
            return getMin(p, gb, alpha, beta, currentPly);
        }
    }
    
    static int getMax(Player p, GameBoard *gb, double alpha, double beta, int currentPly) {
        char indexOfBestMove = 'N';
        for (char theMove : gb->getAvailableMoves()) {
            GameBoard modifiedBoard = *gb;
            modifiedBoard.addBead(Bead(p.getColor()), theMove);
            int score = alphaBetaPruning(p, &modifiedBoard, alpha, beta, currentPly);
            
            if (score > alpha) {
                alpha = score;
                indexOfBestMove = theMove;
            }
            
            if (alpha >= beta) {
                break;
            }
        }
        
        if (indexOfBestMove != 'N') {
            gb->addBead(Bead(p.getColor()), indexOfBestMove);
        }
        
        return (int) alpha;
    }
    
    static int getMin(Player p, GameBoard *gb, double alpha, double beta, int currentPly) {
        char indexOfBestMove = 'N';
        
        for (char theMove : gb->getAvailableMoves()) {
            GameBoard modifiedBoard = *gb;
            modifiedBoard.addBead(Bead(p.getColor()), theMove);
            
            int score = alphaBetaPruning(p, &modifiedBoard, alpha, beta, currentPly);
            
            if (score < beta) {
                beta = score;
                indexOfBestMove = theMove;
            }
            
            if (alpha >= beta) {
                break;
            }
        }
        
        if (indexOfBestMove != 'N') {
            gb->addBead(Bead(p.getColor()), indexOfBestMove);
        }
        
        return (int) beta;
    }
};
