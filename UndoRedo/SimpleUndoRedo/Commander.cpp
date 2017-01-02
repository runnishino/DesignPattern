//
// Created by RunNishino on 2016/12/7.
//

#include "Commander.h"

Commander::Commander(Command* command) {
    undoStack.push(command);
}

Commander::~Commander() {
    while (!undoStack.empty()){
        delete(undoStack.top());
        undoStack.pop();
    }
    while (!redoStack.empty()){
        delete(redoStack.top());
        redoStack.pop();
    }
}

void Commander::ExecuteCommand(Command *command) {
    command->Execute();
    undoStack.push(command);
}

void Commander::Undo() {
    if (undoStack.size()<2){
        cout << "Undo Failed" << endl;
        return;
    }
    cout << "Undo:";

    auto command = undoStack.top();

    redoStack.push(command);
    undoStack.pop();

    command = undoStack.top();
    command->Execute();
}

void Commander::Redo() {
    if (redoStack.empty()){
        cout << "Redo Failed" << endl;
        return;
    }
    cout << "Redo:";

    auto command = redoStack.top();
    command->Execute();

    redoStack.pop();
    undoStack.push(command);
}