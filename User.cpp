//
// Created by Simone on 09/02/2023.
//

#include <iostream>
#include "User.h"

bool User::addItem(const Item &item, int quantity, std::string listName) const {
    auto itr = lists.begin();
    while ((itr != lists.end()) && ((*itr)->getListName() != listName)) {
        itr++;
    }
    if (itr != lists.end()) {
        (*itr)->insertItem(item, quantity);
        return true;
    }
    return false;
}

bool User::createList(const std::string &listName) {
    bool result = false;
    if (!searchList(listName)) {
        std::shared_ptr<ShoppingList> list = std::make_shared<ShoppingList>(listName);
        lists.push_back(list);
        result = true;
    }
    return result;
}

bool User::removeItem(const std::string &itemName, const std::string &listName) const {
    auto itr = lists.begin();
    while ((itr != lists.end()) && ((*itr)->getListName() != listName)) {
        itr++;
    }
    if (itr != lists.end()) {
        return (*itr)->eraseItem(itemName);
    }
    return false;
}

void User::showList(const std::string &listName) {
    for (auto i: lists) {
        if (i->getListName() == listName) {
            i->showList();
        }
    }
}

std::string User::getUsername() const {
    return username;
}

bool User::searchList(const std::string &listName) const {
    bool result = false;
    for (auto list: lists) {
        if (list->getListName() == listName)
            result = true;
    }
    return result;
}


