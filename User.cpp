//
// Created by mattia on 25/08/21.
//

#include "User.h"

const string &User::getUserName() const {
    return userName;
}

void User::setUserName(const string &userName) {
    User::userName = userName;
}

int User::getListNum() const {
    return shoppingLists.size();
}

int User::getObjNum() const {
    return objNum;
}

bool User::isObjectStatus() const {
    return objectStatus;
}

bool User::isListStatus() const {
    return listStatus;
}

void User::removeList(const string &listName) {
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

int User::getQuantity(const string &listName, const string &objectName) {
    auto it = shoppingLists.begin();
    while (it != shoppingLists.end()) {
        if (it->getListName() == listName) {
            return it->checkName(objectName);
        }
    }
    return 0;
}


void User::searchListAdd(const string &listName, const articolo &a) {
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

void User::searchListRemove(const string &listName, const string &objectName) {
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

void User::addSharedList(const User &u) {
    auto it = u.shoppingLists.begin();
    while (it != u.shoppingLists.end()) {
        if (it->isShareable()) {
            shoppingLists.push_back(*it);
        } else {
            ++it;
        }
    }
}

int User::buySomething(const string &objectName, const string &listName) {
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

int User::deselectPurchase(const string &objectName, const string &listName) {
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



