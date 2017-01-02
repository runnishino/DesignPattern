//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_COMMANDMANAGER_H
#define UNDOREDO_COMMANDMANAGER_H

#include "Singleton.h"
#include <stack>
#include "BaseCommandManager.h"
#include "Subject.h"

class BaseCommand;

class CommandManager:public BaseCommandManager,public Subject{
    class UndoRedoStateInspector{
        friend class CommandManager;

    private:
        UndoRedoStateInspector(CommandManager* commandManager);
        ~UndoRedoStateInspector();
        CommandManager* m_pCommandManager;
        bool Undoable;
        bool Redoable;
    };
    friend class Singleton<CommandManager>;

private:
    std::stack<BaseCommand*> stackUndo;
    std::stack<BaseCommand*> stackRedo;

    CommandManager();
    ~CommandManager();
    CommandManager(const CommandManager& rhs);
    CommandManager&operator = (const CommandManager& rhs);

    void PushUndoCommand(BaseCommand * command);
    BaseCommand* PopUndoCommand();
    void PushRedoCommand(BaseCommand * command);
    BaseCommand* PopRedoCommand();
    void DeleteUndoCommands();
    void DeleteRedoCommands();

public:
    static CommandManager* Instance();

    bool CallCommand(BaseCommand* command);
    void ClearAllCommands();
    void Undo();
    void Redo();
    bool CanUndo() const;
    bool CanRedo() const;
};

//#define CALLCOMMAND(Command) CommandManager::Instance()->CallCommand(Command)
//#define UNDO CommandManager::Instance()->Undo()
//#define REDO CommandManager::Instance()->Redo()
//#define CLEARALLCOMMANDS CommandManager::Instance()->ClearAllCommands();
//#define CANUNDO CommandManager::Instance()->CanUndo()
//#define CANREDO CommandManager::Instance()->CanRedo()

#endif //UNDOREDO_COMMANDMANAGER_H
