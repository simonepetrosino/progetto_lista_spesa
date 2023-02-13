#include <iostream>
#include "User.h"

int main() {
    User user("Simone");
    user.createList("Lista di Simone");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    Item z("Detersivo", 2);
    user.addItem(x, 10, "Lista di Simone");
    user.addItem(y, 4, "Lista di Simone");
    user.addItem(z, 7, "Lista di Simone");
    user.showList("Lista di Simone");
    user.removeItem("Acqua", "Lista di Simone");
    user.showList("Lista di Simone");
    Item prova("Latte", Item::BEVERAGES);
    user.addItem(prova, 3, "Lista di");
    user.showList("Lista di");
    user.removeItem("Limon", "Lista di Simone");
    user.showList("Lista di Simone");


    return 0;
}
