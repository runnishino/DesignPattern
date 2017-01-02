//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_COMMANDER_H
#define UNDOREDO_COMMANDER_H

#include <iostream>
#include <stack>
#include <string>
#include "Command.h"
using namespace std;

class Commander{
private:
    stack<Command*> undoStack;
    stack<Command*> redoStack;
public:
    Commander(Command* command);
    ~Commander();

    void ExecuteCommand(Command* command);
    void Undo();
    void Redo();
};

#endif //UNDOREDO_COMMANDER_H
