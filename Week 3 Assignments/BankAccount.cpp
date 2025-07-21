#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    double balance;

    void saveTransaction(const string& type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << " | Balance: $" << balance << endl;
            file.close();
        }
    }

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        saveTransaction("Deposit", amount);
    }

    void purchase(double amount) {
        if (amount <= balance) {
            balance -= amount;
            saveTransaction("Purchase", amount);
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    void printBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account;

    account.deposit(200);         
    account.purchase(30);         
    account.purchase(50);         
    account.printBalance();       

    return 0;
}
