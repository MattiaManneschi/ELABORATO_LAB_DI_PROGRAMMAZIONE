//
// Created by mattia on 07/09/21.
//
#include "gtest/gtest.h"
#include "../View.h"

TEST(User, WorkingUser) {
    User user;
    user.setUserName("MARCO");

    ASSERT_EQ(0, user.getListNum());
    ASSERT_EQ(0, user.getObjNum());
    EXPECT_EQ(false, user.isObjectStatus());

    articolo firstArticle;

    firstArticle.objectName = "MANICO";
    firstArticle.qty = 1;

    ShoppingList shoppingList;

    shoppingList.setListName("LISTA");

    user.addList(shoppingList);
    EXPECT_EQ(true, user.isListStatus());


    try {
        user.searchListAdd((string &) "FOO", firstArticle);
    }
    catch (invalid_argument &err) {
        SUCCEED();
    }

    try {
        user.searchListRemove((string &) "FOO", (string &) "FOO_1");
    }
    catch (invalid_argument &err) {
        SUCCEED();
    }

    try {
        user.buySomething((string &) "FOO", (string &) "FOO_2");
    }
    catch (invalid_argument &err) {
        SUCCEED();
    }

    try {
        user.deselectPurchase((string &) "FOO", (string &) "FOO_3");
    }
    catch (invalid_argument &err) {
        SUCCEED();
    }


    shoppingList.addObject(firstArticle);


    user.searchListAdd(const_cast<string &>(shoppingList.getListName()), firstArticle);
    EXPECT_EQ(true, user.isObjectStatus());


    user.searchListRemove(const_cast<string &>(shoppingList.getListName()), (string &) firstArticle.objectName);
    EXPECT_EQ(false, user.isObjectStatus());


    user.removeList(const_cast<string &>(shoppingList.getListName()));
    EXPECT_EQ(false, user.isListStatus());

}


