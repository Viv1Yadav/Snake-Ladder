//
// Created by vyrao on 27-07-2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;

class Player {
    string name;
    int id;
    static int nextId;

public:
    Player(string name);
    string getName();
    int getId();
};



#endif //PLAYER_H
