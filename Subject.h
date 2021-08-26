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

    virtual void notifyObserver(string a, string b) = 0;

    virtual ~Subject() = 0;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SUBJECT_H
