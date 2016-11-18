//  GameBoard.cpp

#include <iostream>
#include "GameBoard.hpp"

GameBoard::GameBoard(std::vector<Player> playersPlaying) {
    //Human player always goes first.
    players = playersPlaying;
    currTurn = playersPlaying.at(0);
    currTurnIdx = 0;
}

void GameBoard::addBead(Bead b, char pegId) {
    int pegIdx = (pegId - 65) % 8;
    this->board.at(pegIdx).addBead(b);
    currTurnIdx = currTurnIdx == 0 ? 1 : 0;
    setCurrentTurn(players.at(currTurnIdx));
}

Player GameBoard::getCurrentTurn() {
    return currTurn;
}

void GameBoard::setCurrentTurn(Player p) {
    currTurn = p;
}


void GameBoard::printBoard() {
    for (int l = 0; l < 3; l++) {
        for (int i = 0; i < 8; i++) {
            this->board.at(i).printBeadAtLevel(l);
            if (i == 2) std::cout << std::endl << " ";
            else if (i == 4) std::cout << std::endl;
        }

        std::cout << "\n\n";
    }
}

Peg GameBoard::at(int n) {
    return board.at(n);
}

std::vector<char> GameBoard::getAvailableMoves() {
    std::vector<char> result;

    for (int i = 0; i < board.size(); i++) {
        if (!board.at(i).isFull()) {
            result.push_back((char) 65+i);
        }
    }

    return result;
}

bool GameBoard::isFull() {
    //Check if any peg is empty. If it is, that means the board is not full.
    for (auto peg = board.begin(); peg != board.end(); peg++) {
        if (!peg->isFull()) return false;
    }

    //The board is full, calculate the score, let them know who won.
    return true;
}
