//
//  ConsoleClient.cpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-11-12.
//  Copyright © 2016 Fahad. All rights reserved.
//

#include "ConsoleClient.hpp"


ConsoleClient::ConsoleClient() {}

Color ConsoleClient::getPlayerColor() {
    Color result = WHITE;
    std::string playerChoice = "";
    std::cout << "Please pick a color, R for Red, W for White: ";
    std::cin >> playerChoice;
    playerChoice = to_lower(playerChoice);
    
    if (playerChoice == "r") {
        result = RED;
        AIColor = WHITE;
    } else if (playerChoice == "w") {
        result = WHITE;
        AIColor = RED;
    } else {
        std::cout << "Error, please enter either R or W";
        getPlayerColor();
    }
    
    return result;
}

Color ConsoleClient::getAIColor() {
    return AIColor;
}

char ConsoleClient::getPlayerMove() {
    char result = 'a';
    
    std::cout << "Please pick a peg (enter a letter from A-H): ";
    
    std::cin >> result;
    char toLowerResult = tolower(result);
    int code = toLowerResult - 97;
    if (code < 0 || code > 7) {
        std::cout << "Error, please enter a peg from (A-H)";
        return getPlayerMove();
    }
    
    return result;
}

bool ConsoleClient::promptExplanation() {
    return prompt("Would you like a simple explanation of the game? (Y/N): ");
}

bool ConsoleClient::playAgain() {
    return prompt("Would you like to play again? (Y/N)");
}

bool ConsoleClient::prompt(std::string message) {
    std::string result;
    std::cout << message;
    std::cin >> result;
    result = to_lower(result);
    std::cout << std::endl;
    return result == "y";
}

void ConsoleClient::explainGame() {
    std::string sb = "Welcome to 3D-TTT by Fahad.\r\n"
    "\r\n"
    "Here is how the game works:\r\n"
    "\r\n"
    "When the game starts, you will be prompted to choose your colour (Either red or white). Then asked to make a move.\r\n"
    "\r\n"
    "After each move, you will be presented with a printout of the current state of the game.\r\n"
    "\r\n"
    "PRINTOUT EXPLAINED:\r\n"
    "\r\n"
    "The printout will display 3 boards separately on new lines, from level 1 to level 3. \r\n"
    "\r\n"
    "`*` indicates that level is unoccupied \r\n"
    "`R` indicates a red peg sits there.\r\n"
    "`W` indicates a white peg.\r\n"
    "\r\n"
    "(Level 1 below)\r\n"
    "\r\n"
    "A B C\r\n"
    " D E\r\n"
    "F G H\r\n"
    "\r\n"
    "(Level 2 below)\r\n"
    "\r\n"
    "A B C\r\n"
    " D E\r\n"
    "F G H\r\n"
    "\r\n"
    "(Level 3 below)\r\n"
    "\r\n"
    "A B C\r\n"
    " D E\r\n"
    "F G H\r\n"
    "\r\n"
    "HOW TO PLAY:\r\n"
    "Simply follow the prompts. When the board is filled, the game will exit and display the winner, and ask if you want to play again.\r\n"
    "\r\n"
    "Enjoy!\r\n"
    "\r\n"
    "---------------------------------------------\r\n";
    
    std::cout << sb;
}

std::string ConsoleClient::to_lower(std::string str) {
    
    for(unsigned int i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    
    return str;
}
