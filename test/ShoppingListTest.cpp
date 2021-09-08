//
// Created by mattia on 07/09/21.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingList, WorkingShoppingList) {
    ShoppingList shoppingList;
    ASSERT_FALSE(shoppingList.isShareable());
    ASSERT_EQ(0, shoppingList.getNumOfObjects());

    try {
        shoppingList.removeObject((string &) "OGGETTO");
    }
    catch (invalid_argument &err) {
        SUCCEED();
    }


    articolo firstArticle;
    firstArticle.objectName = "SCOPA";
    firstArticle.qty = 1;

    EXPECT_EQ(1, shoppingList.addObject(firstArticle));

    EXPECT_EQ(true, shoppingList.searchToPurchase(firstArticle.objectName));

    EXPECT_EQ(0, shoppingList.removeObject(firstArticle.objectName));

}
