#include <iostream>
#include "Command.h"
#include "Commander.h"
#include "InputCommand.h"

using namespace std;

int main() {
    Commander* commander = new Commander(new InputCommand("[empty]"));

    commander->ExecuteCommand(new InputCommand("1234"));
    commander->ExecuteCommand(new InputCommand("567"));
    commander->ExecuteCommand(new InputCommand("xxx"));

    commander->Undo();
    commander->Undo();

    commander->ExecuteCommand(new InputCommand("yyy"));

    commander->Undo();
    commander->Undo();
    commander->Undo();

    commander->Redo();
    commander->Redo();
    commander->Redo();

    delete(commander);
    return 0;
}