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
    ASSERT_TRUE(list.insertItem(item, 5));
    ASSERT_FALSE(list.insertItem(item, 4));
    list.showList();
}

TEST(ShoppingList, TestEraseItem) {
    ShoppingList list("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_FALSE(list.eraseItem("Acqua"));
    list.insertItem(item, 4);
    ASSERT_FALSE(list.eraseItem("Acqu"));
    ASSERT_TRUE(list.eraseItem("Acqua"));
    list.showList();
}

TEST(ShoppingList, TestSearchItem) {
    ShoppingList list("List");
    Item item("Acqua", Item::BEVERAGES);
    list.insertItem(item, 7);
    ASSERT_TRUE(list.searchItem("Acqua"));
    list.eraseItem("Acqua");
    ASSERT_FALSE(list.searchItem("Acqua"));
}

TEST(ShoppingList, TestShowList) {
    ShoppingList list("List");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    Item z("Detersivo", 2);
    list.insertItem(x, 10);
    list.insertItem(y, 4);
    list.insertItem(z, 7);
    list.showList(0);
    list.showList(1);
    list.showList(2);
    list.showList();
}
