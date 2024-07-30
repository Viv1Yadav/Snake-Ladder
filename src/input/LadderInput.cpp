//
// Created by vyrao on 27-07-2024.
//

#include "../../include/LadderInput.h"
#include "../../include/Ladder.h"

#include<iostream>
#include<list>
#include <string>
#include <sstream>

using namespace std;


list<Ladder> LadderInput::getAllLaddersInput(int boardSize){
    string input;
    int numberOfLadders=-1;
    cout<<"Please enter the number of ladders: ";
    getline(cin, input);
    numberOfLadders= stoi(input);
    list <Ladder> allLadders;
    for(int i=0;i<numberOfLadders;i++) {
        cout<<"Please enter feet and cap of ladder number "<<i+1<<" :";
        getline(cin, input);
        istringstream iss(input);
        int feet, cap;
        iss >> feet >> cap;
        if(!feet || !cap) {
            cout<<"Please Enter valid positions"<<endl;
            i--;
        } else if(feet>=cap) {
            cout<<"Ladder's cap (top) can't be behind it's feet"<<endl;
            i--;
        } else if(feet<=0) {
            cout<<"Ladder's feet can't be at 0 or less than 0"<<endl;
            i--;
        } else if(cap>=boardSize) {
            cout<<"Ladder's cap (top) can't be at or greater than at"<<boardSize<<endl;
            i--;
        } else {
            allLadders.push_back(Ladder(feet, cap));
        }
    }
    return allLadders;
}
