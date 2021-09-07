//
// Created by mattia on 07/09/21.
//
#include "gtest/gtest.h"
#include "../View.h"

TEST(View, ViewTest) {
    User user;
    Controller controller(&user);
    View view(&controller, &user);

    ASSERT_TRUE(view.isUserAdded());
}
