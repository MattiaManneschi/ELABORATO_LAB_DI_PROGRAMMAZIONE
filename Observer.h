//
// Created by mattia on 26/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_OBSERVER_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_OBSERVER_H

#include <iostream>

using namespace std;

struct articolo {
    string objectName;
    int qty;

    bool operator==(const articolo &c) const {
        return this->objectName == c.objectName;
    }
};

class Observer {
public:
    virtual void update(string &name, bool oS, int a) = 0;

    virtual ~Observer() = default;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_OBSERVER_H
