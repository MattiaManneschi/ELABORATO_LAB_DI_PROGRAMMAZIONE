//
// Created by mattia on 25/08/21.
//

#include "ShoppingList.h"

const string &ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::setListName(const string &listName) {
    ShoppingList::listName = listName;
}

bool ShoppingList::isShareable() const {
    return shareable;
}

unsigned long ShoppingList::getNumToBuy() const {
    return numToBuy;
}

int ShoppingList::addObject(const articolo &c) {
    for (auto &it: shoppingList) {
        if (it.objectName == c.objectName) {
            it.qty = it.qty + c.qty;
            return shoppingList.size();
        }
    }
    shoppingList.push_back(c);
    numToBuy++;
    return shoppingList.size();
}

int ShoppingList::removeObject(const string &objectName) {
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
                    if (!it->bought) {
                        numToBuy--;
                    }
                    return shoppingList.size();
                } else {
                    it++;
                }
            }
        }
        throw invalid_argument("OGGETTO NON TROVATO");
    }
}

int ShoppingList::checkName(const string &objectName) {
    auto it = shoppingList.begin();
    while (it != shoppingList.end()) {
        if (it->objectName == objectName) {
            cout << "\nOGGETTO TROVATO!";
            return it->qty;
        }
    }
    return 0;
}


bool ShoppingList::searchToPurchase(const string &objectName) {
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

bool ShoppingList::searchToDeselect(const string &objectName) {
    auto it = shoppingList.begin();
    while (it != shoppingList.end()) {
        if (it->objectName == objectName) {
            if (it->bought) {
                it->bought = false;
                numToBuy++;
                return true;
            } else {
                cout << "OGGETTO GIÀ NON ACQUISTATO. ";
                return false;
            }
        } else {
            it++;
        }
    }
    return false;
}



