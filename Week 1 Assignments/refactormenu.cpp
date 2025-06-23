#include <iostream>
using namespace std;

void showMenu() {
    cout << "1. Add\n";
    cout << "2. View\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int option;
    do {
        showMenu();
        cin >> option;
    } while (option != 3);

    return 0;
}
