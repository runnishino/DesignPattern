#include <iostream>
#include "Observer.h"

int main() {

    Observer *observer1 = new ConcreteObserver("observer1");
    Observer *observer2 = new ConcreteObserver("observer2");

    ConcreteSubject* subject = new ConcreteSubject("subject");
    subject->Attach(observer1);
    subject->Attach(observer2);
    subject->SetState(4);
    subject->Notify();
    subject->Detach(observer2);
    subject->SetState(10);
    subject->Notify();

    delete subject;

    return 0;
}