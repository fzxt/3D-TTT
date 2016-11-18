#ifndef AIClient_hpp
#define AIClient_hpp

#include <stdio.h>
#include "GameBoard.hpp"
#include "AlphaBetaPruning.cpp"

/**
 * This class provides an interface to call the AlphaBetaPruning method.
 */

class AIClient {
public:
    void getBestMove(GameBoard *gb);
};

#endif /* AIClient_hpp */
