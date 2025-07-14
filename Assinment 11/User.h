#ifndef USER_H
#define USER_H

#include <iostream>

class User {
public:
    virtual void accessLevel() const; 
    virtual ~User() = default;
};

class Employee : public User {
public:
    void accessLevel() const override; 
};

class InventoryManager : public Employee {
public:
    void accessLevel() const override; 
};

#endif
