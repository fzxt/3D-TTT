#ifndef ConsoleClient_hpp
#define ConsoleClient_hpp

#include <stdio.h>
#include <iostream>

#include "Color.cpp"
#include "Player.hpp"

class ConsoleClient {
public:
    ConsoleClient();
    Color getPlayerColor();
    Color getAIColor();
    /**
     * Prompts a user if they want an explanation to the game.
     * @return true if they do.
     */
    bool promptExplanation();
    /**
     * Promps the user if they want to play again.
     * @return true if they do.
     */
    bool playAgain();
    /**
     * Method to print to the console an explanation of the game.
     */
    void explainGame();
    /**
     * Prompts the user to pick a peg.
     * @return character representing a peg (A-H)
     */
    char getPlayerMove();
private:
    Color playerColor;
    Color AIColor;
    bool prompt(std::string message);
    std::string to_lower(std::string str);
};


#endif /* ConsoleClient_hpp */
