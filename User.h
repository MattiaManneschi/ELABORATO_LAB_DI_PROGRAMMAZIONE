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
    list<ShoppingList> shoppingLists;
    int listNum = 0;
    list<Observer *> observers;
    int objNum = 0;
    bool objectStatus = false;

public:
    const string &getUserName() const;

    void setUserName(const string &userName);

    void addList(const ShoppingList &s) {
        shoppingLists.push_back(s);
    }

    void removeList(string &listName) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                shoppingLists.erase(it++);
                listNum--;
            } else {
                ++it;
            }
        }
    }

    int getQuantity(string &listName, string &objectName) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                return it->checkName(objectName);
            }
        }
        return 0;
    }

    void searchListAdd(string &listName, const articolo &a) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                cout << "LISTA TROVATA\n";
                goto label1;
            } else {
                ++it;
            }
            cout << "LISTA NON TROVATA!";
            exit(0);
        }
        label1:
        objNum = it->addObject(a);
        objectStatus = true;
        notify(a.objectName);
    }

    void searchListRemove(string &listName, string &objectName) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                goto label1;
            } else {
                ++it;
            }
        }
        label1:
        objNum = it->removeObject(objectName);
        objectStatus = false;
        notify(objectName);
    }

    void addSharedList(const User &u) {
        auto it = u.shoppingLists.begin();
        while (it != u.shoppingLists.end()) {
            if (it->isShareable()) {
                shoppingLists.push_back(*it);
            } else {
                ++it;
            }
        }
    }

    void registerObserver(Observer *o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer *o) override {
        observers.remove(o);
    }

    void notify(string name) override {
        for (auto &ell: observers) {
            ell->update(name, objectStatus, objNum);
        }
    }


};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
