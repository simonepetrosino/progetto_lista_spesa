//
// Created by Simone on 09/02/2023.
//

#ifndef PROGETTO_LISTA_SPESA_USER_H
#define PROGETTO_LISTA_SPESA_USER_H


#include <string>
#include <list>
#include "ShoppingList.h"
#include "Item.h"
#include <memory>

class User {
public:
    User(std::string name) : username(name) {}

    void createList(std::string listName);

    void addItem(const Item &item, int quantity, std::string listName) const;

    void removeItem(std::string itemName, std::string listName) const;

    void showList(std::string listName);

private:
    std::string username;
    std::list<std::shared_ptr<ShoppingList>> lists;
};


#endif //PROGETTO_LISTA_SPESA_USER_H
