//
// Created by vyrao on 27-07-2024.
//
#include<iostream>
#include "../../include/SnakeAndLadderService.h"
#include "../../include/Board.h"
#include "../../include/Player.h"
#include "../../include/Snake.h"
#include "../../include/Ladder.h"
#include "../../include/Dice.h"
#include "../../include/SnakeInput.h"
#include "../../include/LadderInput.h"
#include "../../include/PlayerInput.h"

#include<queue>
#include<list>

#include "../../include/LadderInput.h"
#include "../../include/LadderInput.h"

using namespace std;

SnakeAndLadderService::SnakeAndLadderService() : snakeAndLadderBoard(100){
    dice = Dice();
    totalNumberOfPlayers = 0;
    isGameFinished = false;
}

void SnakeAndLadderService::setPlayers(list<Player> players) {
    this->totalNumberOfPlayers = players.size();
    unordered_map<int, int> playerTokens;
    for(Player player: players) {
        this->players.push(player);
        playerTokens[player.getId()] = 0;
    }
    this->snakeAndLadderBoard.setPlayerTokens(playerTokens);
}

void SnakeAndLadderService::setSnakes(list<Snake> snakes) {
    this->snakeAndLadderBoard.setSnakes(snakes);
}

void SnakeAndLadderService::setLadders(list<Ladder> ladders) {
    this->snakeAndLadderBoard.setLadders(ladders);
}

int SnakeAndLadderService::checkForSnakesAndLaddersAndGetFinalPosition(Player player,int newCell) {
    int prevCell=-1;
    while(newCell!=prevCell) {
        prevCell=newCell;
        for(Snake snake: this->snakeAndLadderBoard.getSnakes()) {
            if(snake.getHead() == newCell) {
                cout<<player.getName()<<" encountered a snake at "<< snake.getHead()<<" which took him/her back to "<< snake.getTail()<<endl;
                newCell = snake.getTail();
            }
        }
        for(Ladder ladder: this->snakeAndLadderBoard.getLadders()) {
            if(ladder.getFeet() == newCell) {
                cout<<player.getName()<<" encountered a ladder at "<< ladder.getFeet()<<" which took him/her to "<< ladder.getCap()<<endl;
                newCell = ladder.getCap();
            }
        }
    }
    return newCell;
}

void SnakeAndLadderService::movePlayer(Player player, int cellsToMove) {
    int boardSize = this->snakeAndLadderBoard.getSize();
    int prevCell = this->snakeAndLadderBoard.getPlayerTokens()[player.getId()];
    if(prevCell==0) {
        if(cellsToMove==6) {
            cellsToMove = 1;
        } else {
            cout<<player.getName()<<" can't move as a 6 is required to come at 1 from 0 :("<<endl;
            cellsToMove = 0;
        }
    }
    int newCell = prevCell + cellsToMove;
    if(newCell<=boardSize) {
        newCell = checkForSnakesAndLaddersAndGetFinalPosition(player,newCell);
    } else {
        cout<<player.getName()<<" can't move forward as he needs "<<boardSize-prevCell<<" to win :("<<endl;
        newCell = prevCell;
    }
    unordered_map<int, int> newTokenPositions(this->snakeAndLadderBoard.getPlayerTokens());
    newTokenPositions[player.getId()]=newCell;
    this->snakeAndLadderBoard.setPlayerTokens(newTokenPositions);
    if(newCell==prevCell) {
        cout<< player.getName()<<" is still at "<< prevCell<<" :("<<endl;
    } else {
        cout<<player.getName()<<" reached to cell "<< newCell<< " from "<< prevCell<< endl;
    }
}

bool SnakeAndLadderService::checkPlayerWon(Player player) {
    int lastCell = this->snakeAndLadderBoard.getSize();
    int currentPostion = snakeAndLadderBoard.getPlayerTokens()[player.getId()];
    return lastCell == currentPostion;
}

bool SnakeAndLadderService::hasGameEnded() {
    return this->totalNumberOfPlayers != this->players.size();
}

void SnakeAndLadderService::takeAndSetInputs() {
    list<Snake> allSnakes = SnakeInput().getAllSnakesInput(this->snakeAndLadderBoard.getSize());
    this->setSnakes(allSnakes);
    list<Ladder> allLadders = LadderInput().getAllLaddersInput(this->snakeAndLadderBoard.getSize());
    this->setLadders(allLadders);
    list<Player> allPlayers = PlayerInput().getAllPlayersInput();
    this->setPlayers(allPlayers);
}


void SnakeAndLadderService::startGame() {
    this->takeAndSetInputs();
    cout<<"The game has been started!"<<endl;
    while (!hasGameEnded()) {
        Player currentPlayer = this->players.front();
        this->players.pop();
        cout<<currentPlayer.getName()<<" is rolling the dice ...."<<endl;
        int diceRollResult = dice.roll();
        cout<<currentPlayer.getName()<<" got "<< diceRollResult<<endl;
        movePlayer(currentPlayer, diceRollResult);
        if(checkPlayerWon(currentPlayer)) {
            cout<<currentPlayer.getName()<<" won the game and came at "<< totalNumberOfPlayers - players.size()<< " position"<<endl;
        } else {
            players.push(currentPlayer);
        }

    }
}






