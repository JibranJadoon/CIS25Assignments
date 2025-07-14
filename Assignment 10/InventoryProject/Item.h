#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    double price;

public:
    Item();
    Item(std::string itemName, double itemPrice);
    void setName(std::string itemName);
    void setPrice(double itemPrice);
    std::string getName() const;
    double getPrice() const;
    void display() const;
};

#endif
