//
// Created by mattia on 25/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H

#include <list>
#include "Subject.h"

class ShoppingList {
protected:
    string listName;
    list <articolo> shoppingList;
    bool shareable;
    unsigned long int numToBuy = shoppingList.size();

public:

    explicit ShoppingList(bool s = false) : shareable(s) {};

    const string &getListName() const;

    void setListName(const string &listName);

    int addObject(const articolo &c);

    int removeObject(string &objectName);

    bool isShareable() const;

    void setShareable() {
        this->shareable = true;
    }

    int checkName(string &objectName);

    int getNumOfObjects() const {
        return shoppingList.size();
    }

    bool searchToPurchase(string &objectName);

    bool searchToDeselect(string &objectName);

    unsigned long getNumToBuy() const;


};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
