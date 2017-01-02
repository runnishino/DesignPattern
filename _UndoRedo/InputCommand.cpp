//
// Created by RunNishino on 2016/12/7.
//

#include "InputCommand.h"
using namespace std;

InputCommand::InputCommand(const std::string &input) {
    commandInput = input;
}

InputCommand::~InputCommand() {

}

void InputCommand::Execute() {
    cout << "Current string is " + commandInput << endl;
}