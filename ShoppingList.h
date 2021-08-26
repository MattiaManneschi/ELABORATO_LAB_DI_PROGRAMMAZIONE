//
// Created by mattia on 25/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H

#include <list>
#include "Subject.h"

struct articolo {
    string objectName;
    int qty;
    bool operator==(const articolo &c) const {
        return this->objectName == c.objectName;
    }
};

class ShoppingList : public Subject {
protected:
    string listName;
    list<articolo> shoppingList;
    bool shareable = false;
    int objNum = 0;
    bool objectStatus = false;
    list<Observer *> observers;
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
            objNum++;
            objectStatus = true;
            notifyObserver(this->getListName(), c.objectName);
        }
    }

    void removeObject(const articolo &c) {
        auto it = shoppingList.begin();
        while (it != shoppingList.end()) {
            if (it->objectName == c.objectName) {
                shoppingList.erase(it++);
                objNum--;
                objectStatus = false;
                notifyObserver(this->getListName(), c.objectName);
            } else {
                ++it;
            }
        }
    }

    bool isShareable() const;

    void setShareable() {
        this->shareable = true;
    }

    int checkName(string &objectName) {
        auto it = shoppingList.begin();
        while (it != shoppingList.end()) {
            if (it->objectName == objectName) {
                cout << "\nOggetto trovato!";
                return it->qty;
            }
        }
        return 0;
    }

    void registerObserver(Observer *o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer *o) override {
        observers.remove(o);
    }

    void notifyObserver(string name, string objectName) override {
        auto it = observers.begin();
        while (it != observers.end()) {
            (*it)->update(name, objectName, this->objectStatus);
        }
    }

    int getNumOfObjects() const {
        return objNum;
    }

};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
