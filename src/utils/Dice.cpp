//
// Created by vyrao on 27-07-2024.
//

#include "../../include/Dice.h"
#include <random>
using namespace std;

int Dice::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(1, 6);
    return dist(gen);
}
