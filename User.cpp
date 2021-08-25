//
// Created by mattia on 25/08/21.
//

#include "User.h"

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

const string &User::getEmailAddress() const {
    return emailAddress;
}

void User::setEmailAddress(const string &emailAddress) {
    User::emailAddress = emailAddress;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}
