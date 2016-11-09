//
// Created by RunNishino on 2016/11/8.
//

#ifndef COMPOSITE_DIRECTORY_H
#define COMPOSITE_DIRECTORY_H

#include <vector>
#include "Entry.h"

class Directory: public Entry{
private:
    string name;
    vector<Entry*> directory;

public:
    Directory(string dir_name){
        this->name = dir_name;
    }
    string getName();
    int getSize();
    void printList();
    void printList(string prefix);
    void add(Entry* entry);
};


#endif //COMPOSITE_DIRECTORY_H
