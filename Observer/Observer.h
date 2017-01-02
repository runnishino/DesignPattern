//
// Created by RunNishino on 2016/12/6.
//

#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H

//观察者类和定义被观察者类定义
#include <list>
#include <string>
using namespace std;
typedef int STATE;

//声明观察者基类
class Observer;

//定义被观察者基类
class Subject{
public:
    Subject():subjectState(-1){}        //初始化subjectState为-1
    Subject(string str);
    virtual ~Subject();                 //析构函数虚函数

    void Notify();                      //通知观察者更新
    void Attach(Observer* observer);    //增加观察者
    void Detach(Observer* observer);    //移除观察者

    virtual string GetSubjectName();

    virtual void SetState(STATE state);    // 设置状态
    virtual STATE GetState();              // 得到状态

protected:
    string subjectName;
    STATE subjectState;
    list<Observer*> observers;          //用list存储观察者
};

//具体的被观察者类
class ConcreteSubject:public Subject{
public:
    ConcreteSubject():Subject(){}
    ConcreteSubject(string str);
    virtual ~ConcreteSubject(){}

    virtual void SetState(STATE state);
    virtual STATE GetState();

};


//定义观察者基类
class Observer{
public:
    Observer():observerState(-1){}
    Observer(string str);
    virtual ~Observer(){}

    string GetObserverName();

    //当观察者收到状态变化通知时进行的操作，具体由不同的派生类实现
    virtual void Update(Subject* subject) = 0;

protected:
    string observerName;
    STATE observerState;
};

class ConcreteObserver:public Observer{
public:
    ConcreteObserver():Observer(){}
    ConcreteObserver(string str);
    virtual ~ConcreteObserver(){}

    virtual void Update(Subject* subject);

};




#endif //OBSERVER_OBSERVER_H
