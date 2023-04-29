
#include <iostream>
#include "User.h"

int main() {
    User userX("x");
    User userY("y");
    userX.createList("Lista di x");
    userY.createList("Lista di y");
    userY.attach(userX, "Lista di x");
    Item x("Limone", 0);
    Item y("Acqua", 1);
    Item z("Detersivo", 2);
    userX.addItem(x, "Lista di x");
    userY.addItem(y, "Lista di x");
    userX.checkItem("Limone", "Lista di x");
    userX.showAllLists();
    userY.showAllLists();
    userX.showAllLists();
    userY.detach(userX, "Lista di x");
    userX.addItem(z, "Lista di x");
    userX.showAllLists();
    return 0;
}
