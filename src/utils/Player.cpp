//
// Created by vyrao on 27-07-2024.
//

#include "../../include/Player.h"
#include<string>
using namespace std;

int Player::nextId = 1;

Player::Player(string name) {
    this->name = name;
    this->id = nextId++;
}

string Player::getName() {
    return this->name;
}
int Player::getId() {
    return this->id;
}


