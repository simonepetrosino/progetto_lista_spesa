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

    bool insertItem(const Item &item, int quantity);

    bool eraseItem(const std::string &itemName);

    const std::string &getListName() const;

    void notify() override;

    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void itemModifier(const std::string &itemName, int quantity);

    bool itemsIsPresent(const std::string &itemName) const;

    auto itemSearcher(const std::string &itemName);
private:
    std::string listName;
    std::map<Item, int, ItemComparator> items;
    std::list<Observer *> observers;
};


#endif //PROGETTO_LISTA_SPESA_SHOPPINGLIST_H
