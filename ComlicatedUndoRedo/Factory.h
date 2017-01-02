//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_FACTORY_H
#define UNDOREDO_FACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

template <class AbstractProduct, class IndentifierType, typename ProductCreator = AbstractProduct*(*)()>

class Factory{
private:
    typedef std::map<IndentifierType,ProductCreator> AssocMap;
    AssocMap associations;

    Factory() {}
    Factory(Factory& factory);
    Factory& operator=(const Factory& factory);

public:
    bool Register(const IndentifierType& id, ProductCreator creator){
        associations[id] = creator;
        return true;
    }

    bool UnResister(const IndentifierType& id){
        return associations[id] == 1;
    }

    AbstractProduct* CreateObject(const IndentifierType& id){
        typename AssocMap::const_iterator i = associations.find(id);
        if (i != associations.end())
        {
            return (i->second)();
        }
        return NULL;
    }

    std::vector<typename IndentifierType> Keys() {
        std::vector<IndentifierType> result;
        AssocMap::iterator itr = associations.begin();
        for (; itr!= associations.end(); itr++)
        {
            result.push_back(itr->first);
        }
        return result;
    }

    static Factory* instance()
    {
        static Factory * pFactory = NULL;
        if (!pFactory)
        {
            static Factory factory;
            pFactory = &factory;
        }
        return pFactory;
    }
};

template <class AbstractProduct, class Product>
class RegisterClassToFactory{
public:
    static AbstractProduct* Create(){
        return new Product;
    }

    RegisterClassToFactory(const std::string& id){
        Factory<AbstractProduct,std::string>::instance()->Register(id,RegisterClassToFactory::Create);
    }
};

#endif //UNDOREDO_FACTORY_H
