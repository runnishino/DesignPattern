//
// Created by RunNishino on 2016/12/7.
//

#ifndef UNDOREDO_UTIL_H
#define UNDOREDO_UTIL_H

template <typename T>
void ContainerDeleter(T& Container) {
    for (T::iterator iter = Container.begin(); iter != Container.end(); iter++) {
        delete (*iter);
    }
    Container.clear();
}

#endif //UNDOREDO_UTIL_H
