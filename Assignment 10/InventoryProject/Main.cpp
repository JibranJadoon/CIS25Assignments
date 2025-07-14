// main.cpp
#include "Item.h"
#include <iostream>

int main() {
    Item item1("Notebook", 4.99);
    Item item2;

    item2.setName("Pencil");
    item2.setPrice(0.99);

    item1.display();
    item2.display();

    return 0;
}