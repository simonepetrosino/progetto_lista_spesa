//
// Created by Simone on 09/02/2023.
//

#ifndef PROGETTO_LISTA_SPESA_ITEM_H
#define PROGETTO_LISTA_SPESA_ITEM_H


#include <string>


class Item {
public:
    enum category {
        FOOD = 0,
        BEVERAGES = 1,
        OTHER = 2
    };

    Item(std::string name, int category) : name(std::move(name)), categoryCode(category) {}

    const std::string &getName() const {
        return name;
    }

    int getCategory() const {
        return categoryCode;
    }

private:
    int categoryCode;
    std::string name;
};

class ItemComparator {
public:
    bool operator()(const Item &first, const Item &second) {
        if (first.getName() < second.getName())
            return true;
        else
            return false;
    }
};

#endif //PROGETTO_LISTA_SPESA_ITEM_H
