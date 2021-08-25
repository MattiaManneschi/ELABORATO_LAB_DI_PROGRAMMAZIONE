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
