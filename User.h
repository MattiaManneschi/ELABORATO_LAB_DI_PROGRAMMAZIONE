//
// Created by mattia on 25/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H

#include "ShoppingList.h"

class User {
protected:
    string name, emailAddress, password;
    list<ShoppingList> shoppingLists;
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getEmailAddress() const;

    void setEmailAddress(const string &emailAddress);

    const string &getPassword() const;

    void setPassword(const string &password);

    void addList(const ShoppingList &s) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == s.getListName()) {
                ++it;
                if (it == shoppingLists.end()) {
                    shoppingLists.push_back(s);
                }
            }
        }
    }

    void removeList(const ShoppingList &s) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == s.getListName()) {
                shoppingLists.erase(it++);
            } else {
                ++it;
            }
        }
    }
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
