#include <iostream>
using namespace std;
//Write a C++ program to create a simple banking system in which the initial balance and the rate of interest are read from the keyboard and these values are initialized using the constructor. The destructor member function is defined in this program to destroy the class object created using constructor member function. This program consists of following member functions:
// i. Constructor to initialize the balance and rate of interest
// ii. Deposit - To make deposit
// iii. Withdraw – To with draw an amount
// iv. Compound – To find compound interest
// v. getBalance – To know the balance amount
// vi. Menu – To display menu options
// vii. Destructor

class BankingSystem {
private:
    double balance;
    double interestRate;

public:
    BankingSystem(double initialBalance, double rate) {
        balance = initialBalance;
        interestRate = rate;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void compound() {
        balance += (balance * interestRate / 100.0);
    }

    double getBalance() {
        return balance;
    }

    void displayMenu() {
        cout << "Banking Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Calculate Interest (Compound)" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
    }

    ~BankingSystem() {
        cout << "Account destroyed." << endl;
    }
};

int main() {
    using namespace std;
    double initialBalance, interestRate;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    cout << "Enter interest rate: ";
    cin >> interestRate;

    BankingSystem account(initialBalance, interestRate);
    int choice;

    do {
        account.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                double depositAmount;
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                cout << "Enter withdraw amount: ";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            case 3:
                account.compound();
                break;
            case 4:
                cout << "Balance: " << account.getBalance() << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}