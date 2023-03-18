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
    explicit User(std::string name) : username(std::move(name)) {}

    bool createList(const std::string &listName);

    bool deleteList(const std::string &listName);

    bool addItem(const Item &item, int quantity, const std::string &listName) const;

    bool removeItem(const std::string &itemName, const std::string &listName) const;

    void showList(const std::string &listName, int category = 3);

    void showAllLists(int category = 3);

    std::string getUsername() const;

    void update() override;

    void attach(const User &user, const std::string &listName);

    void detach(const User &user, const std::string &listName);

    bool modifyItem(const std::string &itemName, const std::string &listName, int quantity) const;

    auto listSearcher(const std::string &listName) const;

    bool listIsPresent(const std::string &listName) const;

private:
    std::string username;
    std::list<std::shared_ptr<ShoppingList>> lists;
};


#endif //PROGETTO_LISTA_SPESA_USER_H
