//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_SINGLETON_H
#define UNDOREDO_SINGLETON_H


template <typename T>
class Singleton{
private:
    Singelton(){}
    Singelton(const Singelton& rhs);
    Singelton& operator = (const Singelton& rhs);

public:
    static T* Instance()
    {
        static T* pT = NULL;
        if (!pT)
        {
            static T instance;
            pT = &instance;
        }
        return pT;
    }
};
#endif //UNDOREDO_SINGLETON_H
