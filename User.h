//
// Created by mattia on 25/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H

#include "ShoppingList.h"
#include "Subject.h"

class User : public Subject {
protected:
    string userName;
    list <ShoppingList> shoppingLists;
    list<Observer *> observers;
    int objNum, x;
    bool objectStatus = false;
    bool listStatus = false;

public:

    explicit User(int oN = 0) : objNum(oN) {};

    const string &getUserName() const;

    void setUserName(const string &userName);

    void addList(const ShoppingList &s) {
        shoppingLists.push_back(s);
        this->x = 1;
        listStatus = true;
        notify(s.getListName());
    }

    void removeList(const string &listName);

    int getQuantity(const string &listName, const string &objectName);

    void searchListAdd(const string &listName, const articolo &a);

    void searchListRemove(const string &listName, const string &objectName);

    void addSharedList(const User &u);

    void registerObserver(Observer *o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer *o) override {
        observers.remove(o);
    }

    void notify(string name) override {
        for (auto &ell: observers) {
            ell->update(name, objectStatus, objNum, listStatus, this->x);
        }
    }

    int buySomething(const string &objectName, const string &listName);

    int deselectPurchase(const string &objectName, const string &listName);

    int getListNum() const;

    int getObjNum() const;

    bool isObjectStatus() const;

    bool isListStatus() const;

};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
