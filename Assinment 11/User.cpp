// User.cpp
#include "User.h"

void User::accessLevel() const {
    std::cout << "User: General access.\n";
}

void Employee::accessLevel() const {
    std::cout << "Employee: Limited administrative access.\n";
}

void InventoryManager::accessLevel() const {
    std::cout << "InventoryManager: Full inventory control access.\n";
}
