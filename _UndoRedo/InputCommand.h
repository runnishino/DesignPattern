//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_INPUTCOMMAND_H
#define UNDOREDO_INPUTCOMMAND_H

#include <iostream>
#include "Command.h"
#include <string>

class InputCommand : public Command{
private:
    std::string commandInput;
public:
    InputCommand(const std::string &input);
    ~InputCommand();

    void Execute();
};

#endif //UNDOREDO_INPUTCOMMAND_H
