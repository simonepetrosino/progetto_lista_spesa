//
// Created by Simone on 09/02/2023.
//

#include "ShoppingList.h"
#include <iostream>

void ShoppingList::showList() const {
    std::cout << "Nome lista: " << listName << std::endl;
    for (auto item: items) {
        std::cout << item.first.getName() << " : " << item.second << std::endl;
    }
}


void ShoppingList::insertItem(const Item &item, int quantity) {
    items.insert(std::make_pair(item, quantity));
}

void ShoppingList::eraseItem(std::string itemName) {
    auto itr = begin(items);
    while ((itr->first.getName() != itemName) && (itr != items.end())) {
        itr++;
    }
    if (itr != items.end()) {
        items.erase(itr);
    }
}

const std::string &ShoppingList::getListName() const {
    return listName;
}







