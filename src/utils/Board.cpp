//
// Created by vyrao on 27-07-2024.
//

#include "../../include/Board.h"

Board::Board(int size) {
    this->size = size;
}

int Board::getSize() {
    return this->size;
}

void Board::setLadders(list<Ladder> ladders) {
    this->ladders = ladders;
}

list<Ladder> Board::getLadders() {
    return this->ladders;
}

void Board::setSnakes(list<Snake> snakes) {
    this->snakes = snakes;
}

list<Snake> Board::getSnakes() {
    return this->snakes;
}


void Board::setPlayerTokens(unordered_map<int, int> playerTokens) {
    this->playerTokens = playerTokens;
}

unordered_map<int, int> Board::getPlayerTokens() {
    return this->playerTokens;
}






