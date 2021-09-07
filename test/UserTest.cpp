//
// Created by mattia on 07/09/21.
//
#include "gtest/gtest.h"
#include "../User.h"

TEST(User, WorkingUser) {
    User user;
    ASSERT_EQ(0, user.getListNum());
    ASSERT_EQ(0, user.getObjNum());
    EXPECT_EQ(false, user.isObjectStatus());
}


