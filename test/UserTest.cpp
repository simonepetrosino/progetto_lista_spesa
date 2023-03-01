//
// Created by Simone on 23/02/2023.
//

#include "gtest/gtest.h"

#include "../User.h"

TEST(User, Constructor) {
    User user("User");
    ASSERT_EQ("User", user.getUsername());
}

TEST(User, TestCreateList) {
    User user("User");
    ASSERT_TRUE(user.createList("List"));
    ASSERT_FALSE(user.createList("List"));
}

TEST(User, TestAddItem) {
    User user("User");
    user.createList("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_TRUE(user.addItem(item, 4, "List"));
    ASSERT_FALSE(user.addItem(item, 4, "Lis"));
}

TEST(User, TestRemoveItem) {
    User user("User");
    user.createList("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_FALSE(user.removeItem("Acqua", "List"));
    user.addItem(item, 3, "List");
    ASSERT_TRUE(user.removeItem("Acqua", "List"));
}

TEST(User, TestSearchList) {
    User user("User");
    user.createList("List");
    ASSERT_FALSE(user.searchList("Lis"));
    ASSERT_TRUE(user.searchList("List"));
}

