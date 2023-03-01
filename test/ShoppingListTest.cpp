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
}

TEST(ShoppingList, TestEraseItem) {
    ShoppingList list("List");
    Item item("Acqua", Item::BEVERAGES);
    ASSERT_FALSE(list.eraseItem("Acqua"));
    list.insertItem(item, 4);
    ASSERT_FALSE(list.eraseItem("Acqu"));
    ASSERT_TRUE(list.eraseItem("Acqua"));
}