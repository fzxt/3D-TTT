//AIClient.cpp

#include "AIClient.hpp"

void AIClient::getBestMove(GameBoard *gb) {
    AlphaBetaPruning::run(gb);
}
