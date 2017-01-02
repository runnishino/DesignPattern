//
// Created by RunNishino on 2016/12/7.
//

#include <sstream>
#include "CommandManager.h"
#include "BaseCommand.h"
//#include "Singleton.h"

CommandManager::UndoRedoStateInspector::UndoRedoStateInspector(CommandManager* pCommandManager):
        m_pCommandManager(pCommandManager),
        Undoable(pCommandManager->CanUndo()),
        Redoable(pCommandManager->CanRedo()) {}

CommandManager::UndoRedoStateInspector::~UndoRedoStateInspector() {
    if (Undoable != m_pCommandManager->CanUndo() || Redoable != m_pCommandManager->CanRedo())
    {
        std::stringstream ssData;
        ssData << m_pCommandManager->CanUndo();
        ssData << ',';
        ssData << m_pCommandManager->CanRedo();
//        未实现的Notify函数
//        m_pCommandManager->Notify(NULL, EVENT_UNDOREDOSTATECHANGED, ssData);
    }
}

CommandManager::CommandManager() {
}

CommandManager::~CommandManager() {
    ClearAllCommands();
}

CommandManager* CommandManager::Instance() {
    return Singleton<CommandManager>::Instance();
}

bool CommandManager::CallCommand(BaseCommand* command) {
    UndoRedoStateInspector si(this);

    if (command) {
        if (command->Execute()) {
            PushUndoCommand(command);
            DeleteRedoCommands();
            return true;
        }
        else {
            delete command;
        }
    }

    return false;
}

void CommandManager::ClearAllCommands() {
    UndoRedoStateInspector si(this);

    DeleteUndoCommands();
    DeleteRedoCommands();
}

void CommandManager::Undo() {
    UndoRedoStateInspector si(this);

    BaseCommand* pCommand = PopUndoCommand();
    if (pCommand) {
        if (pCommand->Unexecute()) {
            PushRedoCommand(pCommand);
        }
        else {
            delete pCommand;
        }
    }
}

void CommandManager::Redo() {
    UndoRedoStateInspector si(this);

    BaseCommand* pCommand = PopRedoCommand();
    if (pCommand) {
        if (pCommand->Execute()) {
            PushUndoCommand(pCommand);
        }
        else {
            delete pCommand;
        }
    }
}

bool CommandManager::CanUndo() const {
    return !stackUndo.empty();
}

bool CommandManager::CanRedo() const {
    return !stackRedo.empty();
}

void CommandManager::PushUndoCommand(BaseCommand* command) {
    if (command) {
        stackUndo.push(command);
    }
}

BaseCommand* CommandManager::PopUndoCommand() {
    BaseCommand* command = NULL;
    if (!stackUndo.empty()) {
        command = stackUndo.top();
        stackUndo.pop();
    }
    return command;
}

void CommandManager::PushRedoCommand(BaseCommand* command) {
    if (command) {
        stackRedo.push(command);
    }
}

BaseCommand * CommandManager::PopRedoCommand() {
    BaseCommand* command = NULL;
    if (!stackRedo.empty()) {
        command = stackRedo.top();
        stackRedo.pop();
    }
    return command;
}

void CommandManager::DeleteUndoCommands() {
    while (!stackUndo.empty()) {
        delete stackUndo.top();
        stackUndo.pop();
    }
}

void CommandManager::DeleteRedoCommands() {
    while (!stackRedo.empty()) {
        delete stackRedo.top();
        stackRedo.pop();
    }
}