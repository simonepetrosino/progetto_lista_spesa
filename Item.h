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

    Item(std::string name, int category) : name(std::move(name)), categoryCode(category), bought(false) {}

    const std::string &getName() const {
        return name;
    }

    int getCategory() const {
        return categoryCode;
    }

    bool isBought() const {
        return bought;
    }

    void setBought(bool value) {
        bought = value;
    }

private:
    int categoryCode;
    std::string name;
    bool bought;
};

#endif //PROGETTO_LISTA_SPESA_ITEM_H
