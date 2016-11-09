//
// Created by RunNishino on 2016/11/9.
//

#include <sstream>
#include "Directory.h"
using namespace std;

string Directory::getName(){
    return name;
}

int Directory::getSize() {
    int size = 0;

    for (int i = 0; i<directory.size(); i++){
        size += directory[i]->getSize();
    }
    return size;
}

void Directory::add(Entry* entry){
    directory.push_back(entry);
}

void Directory::printList() {
    printList("");
}

void Directory::printList(string prefix){
//    ostringstream msg;
//    int num = 0;
//
//    msg << prefix << "/" << this->getName();
//    prefix = msg.str();
//    cout << prefix << endl;
//    while(directory.size()>num){
//        directory[num]->printList(prefix);
//        num++;
//    }


    cout << prefix << "/" << this->getName() << "(" << this->getSize() << ")" << endl;
    vector<Entry*>::iterator iter;
    iter = directory.begin();
    while (iter != directory.end()){
        (*iter)->printList(prefix+"/"+this->getName());
        iter++;
    }
}