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
