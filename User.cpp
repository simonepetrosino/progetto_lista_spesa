//
// Created by Simone on 09/02/2023.
//

#include <iostream>
#include "User.h"

void User::addItem(const Item &item, int quantity, std::string listName) const {
    auto itr = lists.begin();
    while ((itr != lists.end()) && ((*itr)->getListName() != listName)) {
        itr++;
    }
    if (itr == lists.end())
        return;
    if (itr != lists.end()) {
        (*itr)->insertItem(item, quantity);
    }
}

void User::createList(std::string listName) {
    std::shared_ptr<ShoppingList> list = std::make_shared<ShoppingList>(listName);
    lists.push_back(list);
}

void User::removeItem(std::string itemName, std::string listName) const {
    auto itr = lists.begin();
    while ((itr != lists.end()) && ((*itr)->getListName() != listName)) {
        itr++;
    }
    if (itr != lists.end()) {
        (*itr)->eraseItem(itemName);
    }
}

void User::showList(std::string listName) {
    for (auto i: lists) {
        if (i->getListName() == listName) {
            i->showList();
        }
    }
}


