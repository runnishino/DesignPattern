//
// Created by RunNishino on 2016/12/6.
//

#include "Observer.h"
#include <iostream>
#include <algorithm>
using namespace std;

Subject::Subject(string str) {
    subjectName = str;
}

string Subject::GetSubjectName() {
    return subjectName;
}

void Subject::Notify() {
    cout << "Notify Observers" << endl;
    list<Observer*>::iterator iter1;
    list<Observer*>::iterator iter2;

    for (iter1 = observers.begin(), iter2 = observers.end(); iter1!=iter2; ++iter1){
        (*iter1)->Update(this);
    }
}

void Subject::Attach(Observer *observer) {
    cout << "Attach Observer " +  observer->GetObserverName() + " to Subject " + GetSubjectName()<< endl;
    observers.push_back(observer);
}

void Subject::Detach(Observer *observer) {
    list<Observer*>::iterator iter;

    iter = find(observers.begin(),observers.end(),observer);
    if (iter!=observers.end()) {
        cout << "Detach observer " + observer->GetObserverName() + " from " + GetSubjectName()<< endl;
        observers.erase(iter);
    }
}

void Subject::SetState(STATE state) {
    cout << "Set SubjectState to " <<  state <<" by subject" << endl;
    subjectState = state;
}

STATE Subject::GetState() {
    cout << "getstate by subject" << endl;
    return subjectState;
}

Subject::~Subject() {
    list<Observer*>::iterator iter1,iter2,tmp;

    for (iter1 = observers.begin(),iter2 = observers.end(); iter1 != iter2;){
        tmp = iter1;
        ++iter1;
        delete(*tmp);
    }
    observers.clear();
}

Observer::Observer(string str) {
    observerName = str;
}

string Observer::GetObserverName() {
    return observerName;
}

ConcreteSubject::ConcreteSubject(string str) {
    subjectName = str;
}

//string ConcreteSubject::GetconcreteSubjectName() {
//    return subjectName;
//}

void ConcreteSubject::SetState(STATE state) {
    cout << "Set SubjectState to " <<  state <<" by subject" << endl;
    subjectState = state;
}

STATE ConcreteSubject::GetState() {
    cout << "Get State by subject, ";
    return subjectState;
}

ConcreteObserver::ConcreteObserver(string str) {
    observerName = str;
}

//string ConcreteObserver::getconcreteObserverName() {
//    return concreteObserverName;
//}

void ConcreteObserver::Update(Subject *subject) {
    if (subject == NULL) return;

    observerState = subject->GetState();
    cout << "Observer " + GetObserverName() +" State is " << observerState << endl;
}