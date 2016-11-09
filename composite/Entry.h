//
// Created by RunNishino on 2016/11/8.
//

#ifndef COMPOSITE_ENTRY_H
#define COMPOSITE_ENTRY_H

#include <string>
#include <iostream>
using namespace std;

class Entry{

public:
    virtual string getName(){};
    virtual int getSize(){};
    virtual void printList(string prefix){};
    virtual void add(Entry *entry){};
};

#endif //COMPOSITE_ENTRY_H
