//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_COMMAND_H
#define UNDOREDO_COMMAND_H

class Command{
public:
    Command(){}
    virtual ~Command(){}

    virtual void Execute() = 0;
};

#endif //UNDOREDO_COMMAND_H
