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
    int objNum;

public:

    explicit ShoppingList(bool s = false, int obN = 0) : shareable(s), objNum(obN) {};

    const string &getListName() const;

    void setListName(const string &listName);

    int addObject(const articolo &c) {
        for (auto &it: shoppingList) {
            if (it.objectName == c.objectName) {
                it.qty = it.qty + c.qty;
                return objNum;
            }
        }
        shoppingList.push_back(c);
        objNum++;
        return objNum;
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
                        objNum--;
                        return objNum;
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
        return objNum;
    }


};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_SHOPPINGLIST_H
