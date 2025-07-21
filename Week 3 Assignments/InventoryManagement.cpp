#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    void input() {
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void display() const {
        cout << "Item: " << name << ", Quantity: " << quantity << endl;
    }
};

void searchItem(Item items[], int size, const string& searchName) {
    for (int i = 0; i < size; ++i) {
        if (items[i].name == searchName) {
            cout << "Found " << searchName << " with quantity: " << items[i].quantity << endl;
            return;
        }
    }
    cout << searchName << " not found in inventory." << endl;
}

int main() {
    const int SIZE = 5;
    Item inventory[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        cout << "\nItem " << i + 1 << ":" << endl;
        inventory[i].input();
    }

    cout << "\n--- Inventory ---" << endl;
    for (int i = 0; i < SIZE; ++i) {
        inventory[i].display();
    }

    string searchName;
    cout << "\nEnter item name to search: ";
    cin >> searchName;
    searchItem(inventory, SIZE, searchName);

    return 0;
}
