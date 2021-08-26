//
// Created by mattia on 25/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H

#include "ShoppingList.h"
#include "Observer.h"

class User : public Observer {
protected:
    string name, emailAddress, password;
    list<ShoppingList> shoppingLists;
    int listNum = 0;
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
                    listNum++;
                }
            }
        }
    }

    void removeList(const ShoppingList &s) {
        auto it = shoppingLists.begin();
        while (it != shoppingLists.end()) {
            if (it->getListName() == s.getListName()) {
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

    void update(string listName, string objectName, bool oS) override {
        if (oS) {
            cout << "L'ARTICOLO " << objectName << " È STATO AGGIUNTO ALLA LISTA " << listName;
        } else {
            cout << "L'ARTICOLO " << objectName << " È STATO RIMOSSO DALLA LISTA " << listName;
        }
    }

};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_USER_H
