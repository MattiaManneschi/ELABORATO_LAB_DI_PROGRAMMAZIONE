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

    void createArticle(string &a, int b, string &c) const {
        articolo articolo1;
        articolo1.objectName = a;
        articolo1.qty = b;
        this->addNewArticle(articolo1, c);
    }

    void addNewArticle(const articolo &a, string &c) const {
        user->searchListAdd(c, a);
    }

    void removeOldArticle(string &listName, string &articleName) const {
        user->searchListRemove(listName, articleName);
    }

    void createNewList(string &answer) const {
        ShoppingList shoppingList;
        shoppingList.setListName(answer);
        user->addList(shoppingList);
    }

    void removeList(string &answer) const {
        user->removeList(answer);
    }

    User *user;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_CONTROLLER_H
