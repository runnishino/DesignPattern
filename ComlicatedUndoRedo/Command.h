//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_COMMAND_H
#define UNDOREDO_COMMAND_H

#include "BaseCommand.h"

class BaseCommandReceiver;

class Command : public BaseCommand {
public:
    Command();
    virtual ~Command();

    virtual bool Execute();
    virtual bool Unexecute();

    void SetReceiver(BaseCommandReceiver* pReceiver, bool bAutoDelete = true);

private:
    Command(const Command& rhs);
    Command& operator=(const Command& rhs);

protected:
    BaseCommandReceiver * m_pReceiver;
    bool m_bAutoDeleteReceiver;
};

#endif //UNDOREDO_COMMAND_H
