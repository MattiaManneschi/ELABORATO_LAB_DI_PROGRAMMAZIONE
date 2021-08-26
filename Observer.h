//
// Created by mattia on 26/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_OBSERVER_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_OBSERVER_H

#include <iostream>

using namespace std;

class Observer {
public:
    virtual void update(string listName, string objectName, bool oS) = 0;

    virtual ~Observer() = 0;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_OBSERVER_H
