//
// Created by mattia on 26/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_SUBJECT_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_SUBJECT_H

#include <iostream>
#include "Observer.h"

using namespace std;

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notify(string name) = 0;

    virtual ~Subject() = default;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SUBJECT_H
