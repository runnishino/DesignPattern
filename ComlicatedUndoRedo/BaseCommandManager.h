//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_BASECOMMANDMANAGER_H
#define UNDOREDO_BASECOMMANDMANAGER_H
class BaseCommand;

class BaseCommandManager{
public:
    virtual BaseCommandManager(){}
    virtual bool CallCommand(BaseCommand* command) = 0;
    virtual void ClearAllCommands() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
    virtual bool CanUndo() const = 0;
    virtual bool CanRedo() const = 0;
};

#endif //UNDOREDO_BASECOMMANDMANAGER_H
