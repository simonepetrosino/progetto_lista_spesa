//
// Created by Simone on 09/02/2023.
//

#include <iostream>
#include "User.h"

auto User::listSearcher(const std::string &listName) const {
    auto itr = lists.begin();
    while ((itr != lists.end()) && ((*itr)->getListName() != listName)) {
        itr++;
    }
    return itr;
}

bool User::addItem(const Item &item, const std::string &listName) const {
    if (listSearcher(listName) != lists.end()) {
        return (*listSearcher(listName))->insertItem(item);
    }
    return false;
}

bool User::createList(const std::string &listName) {
    bool result = false;
    if (!listIsPresent(listName)) {
        std::shared_ptr<ShoppingList> list = std::make_shared<ShoppingList>(listName);
        list->registerObserver(this);
        lists.push_back(list);
        result = true;
    }
    return result;
}

bool User::removeItem(const std::string &itemName, const std::string &listName) const {
    if (listIsPresent(listName)) {
        return (*listSearcher(listName))->eraseItem(itemName);
    }
    return false;
}

void User::showList(const std::string &listName, int category) {
    for (const auto &i: lists) {
        if (i->getListName() == listName) {
            i->showList(category);
        }
    }
}

std::string User::getUsername() const {
    return username;
}

bool User::listIsPresent(const std::string &listName) const {
    bool result = false;
    for (const auto &list: lists) {
        if (list->getListName() == listName)
            result = true;
    }
    return result;
}

void User::update() {
    std::cout << "NOTIFICA " << username << " : la tua lista e' stata modificata" << std::endl;
}

void User::attach(const User &user, const std::string &listName) {
    if (user.listIsPresent(listName)) {
        (*user.listSearcher(listName))->registerObserver(this);
        std::shared_ptr<ShoppingList> list = (*user.listSearcher(listName));
        lists.push_back(list);
    }
}

void User::detach(const User &user, const std::string &listName) {
    if (user.listIsPresent(listName)) {
        (*user.listSearcher(listName))->removeObserver(this);
        deleteList(listName);
    }
}

bool User::deleteList(const std::string &listName) {
    bool result = false;
    if (listIsPresent(listName)) {
        lists.erase(listSearcher(listName));
        result = true;
    }
    return result;
}

void User::showAllLists(int category) {
    std::cout << "Liste di " << getUsername() << std::endl;
    for (const auto &list: lists) {
        list->showList(category);
    }
}

void User::checkItem(const std::string &itemName, const std::string &listName) {
    if (listIsPresent(listName)) {
        std::shared_ptr<ShoppingList> list = (*listSearcher(listName));
        if ((list->itemsIsPresent(itemName))) {
            list->checkItem(itemName);
        }
    }
}

void User::uncheckItem(const std::string &itemName, const std::string &listName) {
    if (listIsPresent(listName)) {
        std::shared_ptr<ShoppingList> list = (*listSearcher(listName));
        if ((list->itemsIsPresent(itemName))) {
            list->uncheckItem(itemName);
        }
    }
}



