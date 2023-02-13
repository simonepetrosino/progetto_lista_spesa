//
// Created by Simone on 09/02/2023.
//

#ifndef PROGETTO_LISTA_SPESA_SHOPPINGLIST_H
#define PROGETTO_LISTA_SPESA_SHOPPINGLIST_H

#include <map>
#include "Item.h"


class ShoppingList {
public:
    ShoppingList(std::string name) : listName(name) {}

    void showList() const;

    void insertItem(const Item &item, int quantity);

    void eraseItem(std::string itemName);

    const std::string &getListName() const;

private:
    std::string listName;
    std::map<Item, int, ItemComparator> items;
};


#endif //PROGETTO_LISTA_SPESA_SHOPPINGLIST_H