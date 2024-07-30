//
// Created by vyrao on 27-07-2024.
//

#include "../../include/PlayerInput.h"
#include "../../include/Player.h"

#include<iostream>
#include<list>
#include <string>
#include <sstream>

using namespace std;


list<Player> PlayerInput::getAllPlayersInput() {
    string input;
    int numberOfPlayers;
    cout<<"Please enter the number of players: ";
    getline(cin, input);
    numberOfPlayers = stoi(input);
    list<Player> allPlayers;
    for(int i=0;i<numberOfPlayers;i++) {
        cout<<"Please enter "<<i+1<<" player name: ";
        string name;
        getline(cin,name);
        allPlayers.push_back(Player(name));
    }
    return allPlayers;
}
