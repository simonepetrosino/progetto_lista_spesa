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
    user.showList("List");
    ASSERT_FALSE(user.removeItem("Acqua", "List"));
    user.addItem(item, "List");
    ASSERT_TRUE(user.removeItem("Acqua", "List"));
}

/*TEST(User, TestListIsPresent) {
    User userX("UserX");
    userX.createList("List");
    ASSERT_FALSE(userX.listIsPresent("Lis"));
    ASSERT_TRUE(userX.listIsPresent("List"));
    userX.showAllLists();
    User userY("UserY");
    userY.attach(userX, "List");
    ASSERT_TRUE(userY.listIsPresent("List"));
    userY.showAllLists();
}*/

TEST(User, TestDeleteList) {
    User user("User");
    user.createList("List");
    ASSERT_TRUE(user.deleteList("List"));
}

/*TEST(User, TestAttach) {
    User userX("x");
    User userY("y");
    userX.createList("List x");
    userY.attach(userX, "List x");
    ASSERT_TRUE(userX.listIsPresent("List x"));
    userY.showAllLists();
}

TEST(User, TestDetach) {
    User userX("x");
    User userY("y");
    userX.createList("List x");
    userY.attach(userX, "List x");
    userY.showAllLists();
    ASSERT_TRUE(userY.listIsPresent("List x"));
    userY.detach(userX, "List x");
    ASSERT_FALSE(userY.listIsPresent("List x"));
    userY.showAllLists();
}*/

TEST(User, TestShowAllLists) {
    User userX("x");
    userX.createList("Lista di x");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    Item z("Detersivo", 2);
    userX.addItem(x, "Lista di x");
    userX.addItem(y, "Lista di x");
    userX.addItem(z, "Lista di x");
    userX.showAllLists(0);
    userX.showAllLists(1);
    userX.showAllLists(2);
    userX.showAllLists();
}

/*TEST(User, TestModifyItem) {
    User userX("x");
    User userY("y");
    userX.createList("List x");
    userY.createList("List y");
    userY.attach(userX, "List x");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    userX.addItem(x, 10, "List x");
    userY.addItem(y, 4, "List y");
    ASSERT_TRUE(userX.modifyItem("Limone", "List x", -5));
    userX.showAllLists();
    ASSERT_TRUE(userY.modifyItem("Limone", "List x", -5));
    userY.showAllLists();
    ASSERT_FALSE(userX.modifyItem("Acqua", "List y", -6));
    ASSERT_TRUE(userY.modifyItem("Acqua", "List y", 3));
    userY.showAllLists();
    ASSERT_TRUE(userY.modifyItem("Acqua", "List y", -10));
    userY.showAllLists();
}*/

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