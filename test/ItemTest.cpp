//
// Created by Simone on 24/02/2023.
//

#include "gtest/gtest.h"

#include "../Item.h"

TEST(Item, Constructor) {
    Item x("Limone", Item::FOOD);
    Item y("Acqua", Item::BEVERAGES);
    Item z("Detersivo", Item::OTHER);
    ASSERT_EQ("Limone", x.getName());
    ASSERT_EQ(0, x.getCategory());
    ASSERT_EQ(1, y.getCategory());
    ASSERT_EQ(2, z.getCategory());
}