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


bool ShoppingList::insertItem(const Item &item, int quantity) {
    if (!searchItem(item.getName())) {
        items.insert(std::make_pair(item, quantity));
        notify();
        return true;
    }
    return false;
}

bool ShoppingList::eraseItem(const std::string &itemName) {
    auto itr = begin(items);
    while ((itr->first.getName() != itemName) && (itr != items.end())) {
        itr++;
    }
    if (itr != items.end()) {
        items.erase(itr);
        notify();
        return true;
    }
    return false;
}

const std::string &ShoppingList::getListName() const {
    return listName;
}

bool ShoppingList::searchItem(const std::string &itemName) const {
    bool result = false;
    for (auto itr: items) {
        if (itr.first.getName() == itemName)
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









