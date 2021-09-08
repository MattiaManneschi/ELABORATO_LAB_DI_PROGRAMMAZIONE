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

    void removeList(string &listName) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                shoppingLists.erase(it++);
                this->x = 1;
                listStatus = false;
                notify(listName);
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
            throw invalid_argument("LISTA NON TROVATA!");
        }
        label1:
        objNum = it->addObject(a);
        objectStatus = true;
        this->x = 0;
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
            throw invalid_argument("LISTA NON TROVATA");
        }
        label1:
        objNum = it->removeObject(objectName);
        objectStatus = false;
        this->x = 0;
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
            ell->update(name, objectStatus, objNum, listStatus, this->x);
        }
    }

    int buySomething(string &objectName, string &listName) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                if (it->searchToPurchase(objectName)) {
                    cout << "OGGETTO ACQUISTATO. \n";
                    return 0;
                } else {
                    throw invalid_argument("OGGETTO NON TROVATO");
                }
            } else {
                throw invalid_argument("LISTA NON TROVATA");
            }
        }
        return 1;
    }

    int deselectPurchase(string &objectName, string &listName) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == listName) {
                if (it->searchToDeselect(objectName)) {
                    cout << "FATTO. OGGETTO ANCORA NON ACQUISTATO. \n";
                    return 0;
                } else {
                    throw invalid_argument("OGGETTO NON TROVATO");
                }
            } else {
                throw invalid_argument("LISTA NON TROVATA");
            }
        }
        return 1;
    }


    int getListNum() const;

    int getObjNum() const;

    bool isObjectStatus() const;

    bool isListStatus() const;

};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
