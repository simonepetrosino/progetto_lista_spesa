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
    ASSERT_TRUE(user.addItem(item, "List"));
    ASSERT_FALSE(user.addItem(item, "Lis"));
}

TEST(User, TestRemoveItem) {
    User user("User");
    user.createList("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_FALSE(user.removeItem("Acqua", "List"));
    user.addItem(item, "List");
    ASSERT_TRUE(user.removeItem("Acqua", "List"));
}

TEST(User, TestListIsPresent) {
    User userX("UserX");
    userX.createList("List");
    ASSERT_FALSE(userX.listIsPresent("Lis"));
    ASSERT_TRUE(userX.listIsPresent("List"));
    User userY("UserY");
    userY.attach(userX, "List");
    ASSERT_TRUE(userY.listIsPresent("List"));
}

TEST(User, TestDeleteList) {
    User user("User");
    user.createList("List");
    ASSERT_TRUE(user.deleteList("List"));
}

TEST(User, TestAttach) {
    User userX("x");
    User userY("y");
    userX.createList("List x");
    userY.attach(userX, "List x");
    ASSERT_TRUE(userX.listIsPresent("List x"));
}

TEST(User, TestDetach) {
    User userX("x");
    User userY("y");
    userX.createList("List x");
    userY.attach(userX, "List x");
    ASSERT_TRUE(userY.listIsPresent("List x"));
    userY.detach(userX, "List x");
    ASSERT_FALSE(userY.listIsPresent("List x"));
}


TEST(User, TestCheckItem) {
    User userX("x");
    userX.createList("List x");
    Item x("Limone", 0);
    userX.addItem(x, "List x");
    ASSERT_FALSE(x.isBought());
    userX.checkItem("Limone", "List x");
    ASSERT_TRUE(x.isBought());
}

TEST(User, TestUncheckItem) {
    User userX("x");
    userX.createList("List x");
    Item x("Limone", 0);
    userX.addItem(x, "List x");
    userX.checkItem("Limone", "List x");
    ASSERT_TRUE(x.isBought());
    userX.uncheckItem("Limone", "List x");
    ASSERT_FALSE(x.isBought());
}