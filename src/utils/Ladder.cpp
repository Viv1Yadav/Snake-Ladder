//
// Created by vyrao on 27-07-2024.
//

#include "../../include/Ladder.h"

Ladder::Ladder(int feet, int cap){
    this->feet=feet;
    this->cap=cap;
}

int Ladder::getFeet(){
    return this->feet;
}

int Ladder::getCap(){
    return this->cap;
}