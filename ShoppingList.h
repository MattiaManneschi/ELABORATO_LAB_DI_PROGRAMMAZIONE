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

    int addObject(const articolo &c) {
        for (auto &it: shoppingList) {
            if (it.objectName == c.objectName) {
                it.qty = it.qty + c.qty;
                return shoppingList.size();
            }
        }
        shoppingList.push_back(c);
        return shoppingList.size();
    }

    int removeObject(string &objectName) {
        if (shoppingList.empty()) {
            throw invalid_argument("LISTA VUOTA");
        } else {
            auto it = shoppingList.begin();
            while (it != shoppingList.end()) {
                if (it == shoppingList.end()) {
                    throw invalid_argument("OGGETTO NON TROVATO");
                } else {
                    if (it->objectName == objectName) {
                        shoppingList.erase(it);
                        return shoppingList.size();
                    } else {
                        it++;
                    }
                }
            }
            throw invalid_argument("OGGETTO NON TROVATO");
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
                cout << "\nOGGETTO TROVATO!";
                return it->qty;
            }
        }
        return 0;
    }

    int getNumOfObjects() const {
        return shoppingList.size();
    }

    bool searchToPurchase(string &objectName) {
        auto it = shoppingList.begin();
        while (it != shoppingList.end()) {
            if (it->objectName == objectName) {
                it->bought = true;
                numToBuy--;
                return true;
            } else {
                it++;
            }
        }
        return false;
    }

    unsigned long getNumToBuy() const;


};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
