//
// Created by Simone on 09/02/2023.
//

#include "ShoppingList.h"
#include <iostream>

void ShoppingList::showList(int category) const {
    std::cout << "Nome lista: " << listName << std::endl;
    for (const auto &item: items) {
        if (category == 3 || item.first.getCategory() == category) {
            std::cout << item.first.getName() << " : " << item.second << std::endl;
        }
    }
}


bool ShoppingList::insertItem(const Item &item, int quantity) {
    if (!itemsIsPresent(item.getName())) {
        items.insert(std::make_pair(item, quantity));
        notify();
        return true;
    }
    return false;
}

auto ShoppingList::itemSearcher(const std::string &itemName) {
    auto itr = items.begin();
    while ((itr != items.end()) && (itr->first.getName() != itemName)) {
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
        if (item.first.getName() == itemName)
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

void ShoppingList::itemModifier(const std::string &itemName, int quantity) {
    if ((*itemSearcher(itemName)).second + quantity <= 0) {
        eraseItem(itemName);
    } else {
        (*itemSearcher(itemName)).second += quantity;
        notify();
    }
}









