//
// Created by RunNishino on 2016/11/9.
//

#include "File.h"
using namespace std;

string File::getName() {
    return name;
}

int File::getSize() {
    return size;
}

void File::printList() {
    printList("");
}
void File::printList(string prefix) {
    cout << prefix << "/" << this->getName() << "(" << this->getSize() << ")" << endl;
}