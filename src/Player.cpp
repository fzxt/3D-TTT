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
