//
// Created by vyrao on 27-07-2024.
//

#include "../../include/SnakeInput.h"
#include "../../include/Snake.h"

#include<iostream>
#include<list>
#include <string>
#include <sstream>

using namespace std;


list<Snake> SnakeInput::getAllSnakesInput(int boardSize) {
    string input;
    int numberOfSnakes;
    cout<<"Please enter the number of Snakes: ";
    getline(cin, input);
    numberOfSnakes = stoi(input);
    list <Snake> allSnakes;
    for(int i=0;i<numberOfSnakes;i++) {
        cout<<"Please enter head and tail of snake number "<<i+1<<" :";
        getline(cin, input);
        istringstream iss(input);
        int head, tail;
        iss >> head >> tail;
        if(!head || !tail) {
            cout<<"Please Enter valid positions"<<endl;
            i--;
        } else if(head<=tail ) {
            cout<<"Snake's head can't be behind it's tail"<<endl;
            i--;
        } else if(tail<=0) {
            cout<<"Snake's tail can't be at 0 or less than 0"<<endl;
            i--;
        } else if(head>=boardSize) {
            cout<<"Snake's head can't be at or greater than at"<<boardSize<<endl;
            i--;
        } else {
            allSnakes.push_back(Snake(head, tail));
        }
    }
    return allSnakes;
}
