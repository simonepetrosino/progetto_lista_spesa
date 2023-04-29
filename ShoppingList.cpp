//
// Created by Simone on 09/02/2023.
//

#include "ShoppingList.h"
#include <iostream>

void ShoppingList::showList(int category) const {
    std::cout << "Nome lista: " << listName << std::endl;
    for (const auto &item: items) {
        if (category == 3 || item.first == category) {
            std::cout << item.second->getName() << " : " << item.second->isBought() << std::endl;
        }
    }
}


bool ShoppingList::insertItem(const Item &item) {
    if (!itemsIsPresent(item.getName())) {
        items.insert(std::make_pair(item.getCategory(), &const_cast<Item &>(item)));
        notify();
        return true;
    }
    return false;
}

std::map<int, Item *>::iterator ShoppingList::itemSearcher(const std::string &itemName) {
    auto itr = items.begin();
    while ((itr != items.end()) && (itr->second->getName() != itemName)) {
        itr++;
    }
    return itr;
}

bool ShoppingList::eraseItem(const std::string &itemName) {
    if (itemsIsPresent(itemName)) {
        items.erase(itemSearcher(itemName));
        notify();
        return true;
    }
    return false;
}

const std::string &ShoppingList::getListName() const {
    return listName;
}

bool ShoppingList::itemsIsPresent(const std::string &itemName) const {
    bool result = false;
    for (const auto &item: items) {
        if (item.second->getName() == itemName)
            result = true;
    }
    return result;
}

void ShoppingList::notify() {
    for (auto observer: observers) {
        observer->update();
    }
}

void ShoppingList::registerObserver(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::removeObserver(Observer *o) {
    observers.remove(o);
}

void ShoppingList::checkItem(const std::string &itemName) {
    if (itemsIsPresent(itemName)) {
        (*itemSearcher(itemName)).second->setBought(true);
    }
}

void ShoppingList::uncheckItem(const std::string &itemName) {
    if (itemsIsPresent(itemName)) {
        (*itemSearcher(itemName)).second->setBought(false);
    }
}

int ShoppingList::totItemsToBuy(int category) const {
    int tot = 0;
    for (const auto &item: items) {
        if (category == 3 || item.first == category) {
            if (!(item.second->isBought())) {
                tot++;
            }
        }
    }
    return tot;
}











