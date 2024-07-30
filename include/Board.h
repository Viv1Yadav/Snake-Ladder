//
// Created by vyrao on 27-07-2024.
//

#ifndef BOARD_H
#define BOARD_H
#include<list>
#include<unordered_map>
using namespace std;

#include "Ladder.h"
#include "Snake.h"



class Board {
    int size;
    list<Snake> snakes;
    list<Ladder> ladders;
    unordered_map<int,int> playerTokens;
public:
    Board(int size);
    int getSize();
    void setSnakes(list<Snake> snakes);
    list<Snake> getSnakes();
    void setLadders(list<Ladder> ladders);
    list<Ladder> getLadders();
    void setPlayerTokens(unordered_map<int, int> playerTokens);
    unordered_map<int, int> getPlayerTokens();
};



#endif //BOARD_H
