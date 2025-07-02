#include <iostream>
#include <fstream>
using namespace std;

class Item {
public:
    string name;
    int quantity;

    void saveToFile() {
        ofstream outFile("items.txt"); 
        if (outFile.is_open()) {
            outFile << name << "," << quantity << endl; 
            outFile.close();
            cout << "Item saved to items.txt successfully!" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile() {
        ifstream inFile("items.txt");
        if (inFile.is_open()) {
            getline(inFile, name, ',');
            inFile >> quantity;
            inFile.close();
            cout << "Loaded from file -> Name: " << name << ", Quantity: " << quantity << endl;
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    Item myItem;

    cout << "Enter item name: ";
    getline(cin, myItem.name);

    cout << "Enter item quantity: ";
    cin >> myItem.quantity;

    myItem.saveToFile();


    return 0;
}
