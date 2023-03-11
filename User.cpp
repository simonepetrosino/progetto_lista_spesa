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
        list->registerObserver(this);
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

void User::showList(const std::string &listName, int category) {
    for (auto i: lists) {
        if (i->getListName() == listName) {
            i->showList(category);
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

void User::update() {
    std::cout << "NOTIFICA " << username << " : la tua lista e' stata modificata" << std::endl;
}

void User::attach(const User &user, std::string listName) {
    if (user.searchList(listName)) {
        auto itr = user.lists.begin();
        while ((itr != user.lists.end()) && ((*itr)->getListName() != listName)) {
            itr++;
        }
        (*itr)->registerObserver(this);
        std::shared_ptr<ShoppingList> list = (*itr);
        lists.push_back(list);
    }
}

void User::detach(const User &user, std::string listName) {
    if (user.searchList(listName)) {
        auto itr = user.lists.begin();
        while ((itr != user.lists.end()) && ((*itr)->getListName() != listName)) {
            itr++;
        }
        (*itr)->removeObserver(this);
        this->deleteList(listName);
    }
}

bool User::deleteList(const std::string &listName) {
    auto itr = lists.begin();
    while ((itr != lists.end()) && ((*itr)->getListName() != listName)) {
        itr++;
    }
    if (itr != lists.end()) {
        lists.erase(itr);
        return true;
    }
    return false;
}

void User::showAllLists(int category) {
    std::cout << "Liste di " << getUsername() << std::endl;
    for (auto list: lists) {
        list->showList(category);
    }
}


