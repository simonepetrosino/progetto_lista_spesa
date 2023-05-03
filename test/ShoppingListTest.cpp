//
// Created by Simone on 24/02/2023.
//

#include "gtest/gtest.h"

#include "../ShoppingList.h"

TEST(ShoppingList, Constructor) {
    ShoppingList list("List");
    ASSERT_EQ("List", list.getListName());
}

TEST(ShoppingList, TestInsertItem) {
    ShoppingList list("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_TRUE(list.insertItem(item));
    ASSERT_FALSE(list.insertItem(item));
}

TEST(ShoppingList, TestEraseItem) {
    ShoppingList list("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_FALSE(list.eraseItem("Acqua"));
    list.insertItem(item);
    ASSERT_FALSE(list.eraseItem("Acqu"));
    ASSERT_TRUE(list.eraseItem("Acqua"));
}

TEST(ShoppingList, TestItemIsPresent) {
    ShoppingList list("List");
    Item item("Acqua", Item::BEVERAGES);
    list.insertItem(item);
    ASSERT_TRUE(list.itemsIsPresent("Acqua"));
    list.eraseItem("Acqua");
    ASSERT_FALSE(list.itemsIsPresent("Acqua"));
}

TEST(ShoppingList, TestCheckItem) {
    ShoppingList list("List");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    list.insertItem(x);
    list.insertItem(y);
    ASSERT_FALSE(x.isBought());
    ASSERT_FALSE(y.isBought());
    list.checkItem("Limone");
    list.checkItem("Acqua");
    ASSERT_TRUE(x.isBought());
    ASSERT_TRUE(y.isBought());
}

TEST(ShoppingList, TestUncheckItem) {
    ShoppingList list("List");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    list.insertItem(x);
    list.insertItem(y);
    list.checkItem("Limone");
    list.checkItem("Acqua");
    list.uncheckItem("Limone");
    list.uncheckItem("Acqua");
    ASSERT_FALSE(x.isBought());
    ASSERT_FALSE(y.isBought());
}

TEST(ShoppingList, TestTotItem) {
    ShoppingList list("List");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    list.insertItem(x);
    list.insertItem(y);
    ASSERT_TRUE(list.totItemsToBuy() == 2);
    ASSERT_TRUE(list.totItemsToBuy(0) == 1);
    ASSERT_TRUE(list.totItemsToBuy(1) == 1);
    ASSERT_TRUE(list.totItemsToBuy(2) == 0);
    list.checkItem("Limone");
    ASSERT_TRUE(list.totItemsToBuy() == 1);
    ASSERT_TRUE(list.totItemsToBuy(0) == 0);
}