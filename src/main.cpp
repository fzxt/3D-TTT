//
//  main.cpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-26.
//  Copyright © 2016 Fahad. All rights reserved.

#include <iostream>

#include "GameBoard.hpp"
#include "ScoreKeeper.hpp"
#include "ConsoleClient.hpp"
#include "AIClient.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<Player> players;
    
    ConsoleClient client = ConsoleClient();
    
    if (client.promptExplanation()) {
        client.explainGame();
    }
    
    Player human = Player(client.getPlayerColor());
    Player ai = Player(client.getAIColor());

    players.push_back(human);
    players.push_back(ai);
    
    GameBoard gb = GameBoard(players);
    
    AIClient aiClient;
    
    while (true) {
        while(!gb.isFull()) {
            cout << endl;
            gb.printBoard();
            
            if (gb.getCurrentTurn() == human) {
                cout << "It's your turn." << "\n\n";
                gb.addBead(Bead(human.getColor()), client.getPlayerMove());
            } else {
                cout << "It's the AI's turn." << endl;
                aiClient.getBestMove(&gb);
            }
        }
        
        gb.printBoard();
        
        ScoreKeeper::printWinner(gb, players);
        
        if (client.playAgain()) {
            gb = GameBoard(players);
        }
    }
    

}
