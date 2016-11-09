//
// Created by RunNishino on 2016/11/8.
//

#ifndef COMPOSITE_FILE_H
#define COMPOSITE_FILE_H

#include <string>
#include <iostream>
#include "Entry.h"
using namespace std;

class File:public Entry{
private:
    string name;
    int size = 0;

public:
    File(string file_name, int file_size){
        name = file_name;
        size = file_size;
    }
    string getName();
    int getSize();
    void printList();
    void printList(string prefix);
};

#endif //COMPOSITE_FILE_H
