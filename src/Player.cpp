//
//  Player.cpp
//  COSC4F00_ASSIGN2
//
//  Created by Fahad on 2016-10-29.
//  Copyright © 2016 Fahad. All rights reserved.
//

#include "Player.hpp"

Player::Player(Color c) {
    this->score = 0;
    this->c = c;
}

int Player::getScore() {
    return this->score;
}

bool operator== (const Player& a1, const Player& a2) {
    return a1.c == a2.c;
}

void Player::setScore(int val) {
    this->score = val;
}

Color Player::getColor() {
    return this->c;
}

void Player::printColor() {
    std::string message =  getColor() == WHITE ? "White" : "Red";
    std::cout << message;
}

