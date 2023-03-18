
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
    userX.addItem(x, 10, "Lista di x");
    userY.addItem(y, 4, "Lista di x");
    userX.showAllLists(1);
    userY.showAllLists(0);
    userX.showAllLists();
    userY.detach(userX, "Lista di x");
    userX.addItem(z, 7, "Lista di x");
    userX.showAllLists();
    return 0;
}
