//
// Created by mattia on 25/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H

#include <iostream>
#include <list>

using namespace std;

struct articolo {
    string objectName;
    int qty;

    bool operator==(const articolo &c) const {
        return this->objectName == c.objectName;
    }
};

class ShoppingList {
protected:
    string listName;
    list<articolo> shoppingList;
public:
    const string &getListName() const;

    void setListName(const string &listName);

    void addObject(const articolo &c) {
        for (auto &it: shoppingList) {
            if (it.objectName == c.objectName) {
                it.qty = it.qty + c.qty;
                exit(0);
            }
            shoppingList.push_back(c);
        }
    }

    void removeObject(const articolo &c) {
        auto it = shoppingList.begin();
        while (it != shoppingList.end()) {
            if (it->objectName == c.objectName) {
                shoppingList.erase(it++);
            } else {
                ++it;
            }
        }
    }

};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
