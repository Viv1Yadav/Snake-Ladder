//
// Created by vyrao on 27-07-2024.
//

#ifndef SNAKEANDLADDERSERVICE_H
#define SNAKEANDLADDERSERVICE_H

#include<queue>
#include<list>

#include "Board.h"
#include "Player.h"
#include"Snake.h"
#include "Ladder.h"
#include "Dice.h"

using namespace std;


class SnakeAndLadderService {

    Board snakeAndLadderBoard;
    Dice dice;
    int totalNumberOfPlayers;
    queue<Player> players;
    bool isGameFinished;
public:
    SnakeAndLadderService();
    void setPlayers(list<Player> players);
    void setLadders(list<Ladder> ladders);
    void setSnakes(list<Snake> snakes);
    int checkForSnakesAndLaddersAndGetFinalPosition(Player player, int newPosition);
    void movePlayer(Player player, int postion);
    bool checkPlayerWon(Player player);
    bool hasGameEnded();
    void startGame();
    void takeAndSetInputs();
};



#endif //SNAKEANDLADDERSERVICE_H
