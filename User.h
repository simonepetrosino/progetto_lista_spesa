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
#include "Observer.h"


class User : public Observer {
public:
    explicit User(std::string name) : username(name) {}

    bool createList(const std::string &listName);

    bool deleteList(const std::string &listName);

    bool addItem(const Item &item, int quantity, std::string listName) const;

    bool removeItem(const std::string &itemName, const std::string &listName) const;

    void showList(const std::string &listName, int category = 3);

    void showAllLists(int category = 3);

    std::string getUsername() const;

    bool searchList(const std::string &listName) const;

    void update() override;

    void attach(const User &user, std::string listName);

    void detach(const User &user, std::string listName);

private:
    std::string username;
    std::list<std::shared_ptr<ShoppingList>> lists;
};


#endif //PROGETTO_LISTA_SPESA_USER_H
