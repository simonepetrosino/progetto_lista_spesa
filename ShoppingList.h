//
// Created by Simone on 09/02/2023.
//

#ifndef PROGETTO_LISTA_SPESA_SHOPPINGLIST_H
#define PROGETTO_LISTA_SPESA_SHOPPINGLIST_H

#include <map>
#include "Item.h"
#include "Subject.h"
#include <list>

class ShoppingList : public Subject {
public:
    explicit ShoppingList(std::string name) : listName(std::move(name)) {}

    void showList(int category = 3) const;

    bool insertItem(const Item &item);

    bool eraseItem(const std::string &itemName);

    const std::string &getListName() const;

    void notify() override;

    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void checkItem(const std::string &itemName);

    void uncheckItem(const std::string &itemName);

    bool itemsIsPresent(const std::string &itemName) const;

    int totItemsToBuy(int category = 3) const;

private:

    std::map<int, Item *>::iterator itemSearcher(const std::string &itemName);

    std::string listName;
    std::map<int, Item *> items;
    std::list<Observer *> observers;
};


#endif //PROGETTO_LISTA_SPESA_SHOPPINGLIST_H
