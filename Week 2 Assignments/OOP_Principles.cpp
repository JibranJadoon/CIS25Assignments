#include <iostream>
using namespace std;

class Item {
public:
    virtual void display() = 0;
};

class Perishable : public Item {
public:
    void display() override {
        cout << "Perishable Item" << endl;
    }
};

class NonPerishable : public Item {
public:
    void display() override {
        cout << "Non-Perishable Item" << endl;
    }
};

int main() {
    Perishable p;
    NonPerishable np;

    Item* itemPtr;

    itemPtr = &p;
    itemPtr->display();

    itemPtr = &np;
    itemPtr->display();

    return 0;
}
