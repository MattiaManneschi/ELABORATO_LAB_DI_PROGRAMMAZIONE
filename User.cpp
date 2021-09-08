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
