//
// Created by RunNishino on 2016/12/7.
//

#include "Command.h"
#include "BaseCommandReceiver.h"

RegisterCommandClass<Command> RegisterCommandClass("Command");

Command::Command(void):
        m_pReceiver(NULL),
        m_bAutoDeleteReceiver(true) {
}

Command::~Command(void) {
    if (m_bAutoDeleteReceiver && m_pReceiver) {
        delete m_pReceiver;
        m_pReceiver = NULL;
    }
}

bool Command::Execute() {
    if (m_pReceiver) {
        return m_pReceiver->Action(false);
    }

    return false;
}

bool Command::Unexecute() {
    if (m_pReceiver) {
        return m_pReceiver->Action(true);
    }

    return false;
}

void Command::SetReceiver(BaseCommandReceiver * pReceiver, bool bAutoDelete) {
    m_pReceiver = pReceiver;
    m_bAutoDeleteReceiver = bAutoDelete;
}