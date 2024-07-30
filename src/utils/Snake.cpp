//
// Created by vyrao on 27-07-2024.
//

#include "../../include/Snake.h"

Snake::Snake(int head, int tail){
    this->head=head;
    this->tail=tail;
}

int Snake::getHead(){
    return this->head;
}

int Snake::getTail(){
    return this->tail;
}