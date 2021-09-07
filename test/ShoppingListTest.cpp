//
// Created by mattia on 07/09/21.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"

TEST(ShoppingList, WorkingShoppingList) {
    ShoppingList shoppingList;
    ASSERT_FALSE(shoppingList.isShareable());
    ASSERT_EQ(0, shoppingList.getNumOfObjects());
}
