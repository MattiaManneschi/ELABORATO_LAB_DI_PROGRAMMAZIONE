//
// Created by mattia on 26/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_CONTROLLER_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_CONTROLLER_H

#include <utility>

#include "User.h"

class Controller {
public:
    explicit Controller(User *u) : user(u) {};

    void createArticle(const string &a, int b, const string &c) const {
        articolo articolo1;
        articolo1.objectName = a;
        articolo1.qty = b;
        this->addNewArticle(articolo1, c);
    }

    void addNewArticle(const articolo &a, const string &c) const {
        user->searchListAdd(c, a);
    }

    void removeOldArticle(const string &listName, const string &articleName) const {
        user->searchListRemove(listName, articleName);
    }

    void createNewList(const string &answer) const {
        ShoppingList shoppingList;
        shoppingList.setListName(answer);
        user->addList(shoppingList);
    }

    void removeList(const string &answer) const {
        user->removeList(answer);
    }

    void buyAnObject(const string &objectName, const string &listName) const {
        int foo = user->buySomething(objectName, listName);
    }

    void deselectObjectToBuy(const string &objectName, const string &listName) const {
        int foo = user->deselectPurchase(objectName, listName);
    }

    User *user;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_CONTROLLER_H
