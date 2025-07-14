// Item.cpp
#include "Item.h"
#include <iostream>

Item::Item() {
    name = "Unknown";
    price = 0.0;
}

Item::Item(std::string itemName, double itemPrice) {
    name = itemName;
    price = itemPrice;
}

void Item::setName(std::string itemName) {
    name = itemName;
}

void Item::setPrice(double itemPrice) {
    price = itemPrice;
}

std::string Item::getName() const {
    return name;
}

double Item::getPrice() const {
    return price;
}

void Item::display() const {
    std::cout << "Item: " << name << ", Price: $" << price << std::endl;
}
