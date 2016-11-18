//  main.cpp

#include <iostream>
// #include <thread>
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
            std::cout << "Your score: " << human.getScore() << std::endl;
            std::cout << "Computer score: " << ai.getScore() << "\n\n";
            gb.printBoard();
            try {
              if (gb.getCurrentTurn() == human) {
                  cout << "It's your turn." << "\n\n";
                  gb.addBead(Bead(human.getColor()), client.getPlayerMove());
                  ScoreKeeper::calcScoreForPlayer(gb, &human);

              } else {
                  cout << "It's the AI's turn." << endl;
                  aiClient.getBestMove(&gb);
              }
            } catch (std::runtime_error) {
              cout << "Error, that peg is full, try again.\n\n";
            }
        }

        gb.printBoard();

        ScoreKeeper::printWinner(gb, players);

        if (client.playAgain()) {
            gb = GameBoard(players);
        }
    }


}
