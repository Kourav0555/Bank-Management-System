#include <iostream>
#include <string>
using namespace std;

// Class representing a bank account
class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor to initialize account
    BankAccount() {
        accountNumber = 0;
        accountHolder = "";
        balance = 0;
    }

    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if(amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Balance: " << balance << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

// Maximum number of accounts
const int MAX_ACCOUNTS = 5;
BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to find account index by account number
int findAccount(int accNo) {
    for(int i = 0; i < accountCount; i++) {
        if(accounts[i].getAccountNumber() == accNo) {
            return i;
        }
    }
    return -1; // Not found
}

// Create a new account
void createAccount() {
    if(accountCount >= MAX_ACCOUNTS) {
        cout << "Bank is full! Cannot create more accounts." << endl;
        return;
    }
    int accNo;
    string name;
    double bal;

    cout << "Enter Account Number: "; cin >> accNo;
    cout << "Enter Account Holder Name: "; cin >> name;
    cout << "Enter Initial Balance: "; cin >> bal;

    if(findAccount(accNo) != -1) {
        cout << "Account already exists!" << endl;
        return;
    }

    accounts[accountCount] = BankAccount(accNo, name, bal);
    accountCount++;
    cout << "Account created successfully!" << endl;
}

// Deposit money
void depositMoney() {
    int accNo; double amount;
    cout << "Enter Account Number: "; cin >> accNo;
    int index = findAccount(accNo);
    if(index != -1) {
        cout << "Enter amount to deposit: "; cin >> amount;
        accounts[index].deposit(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

// Withdraw money
void withdrawMoney() {
    int accNo; double amount;
    cout << "Enter Account Number: "; cin >> accNo;
    int index = findAccount(accNo);
    if(index != -1) {
        cout << "Enter amount to withdraw: "; cin >> amount;
        accounts[index].withdraw(amount);
    } else {
        cout << "Account not found!" << endl;
    }
}

// Display account details
void displayAccount() {
    int accNo;
    cout << "Enter Account Number: "; cin >> accNo;
    int index = findAccount(accNo);
    if(index != -1) {
        accounts[index].display();
    } else {
        cout << "Account not found!" << endl;
    }
}

// Display all accounts
void displayAllAccounts() {
    if(accountCount == 0) {
        cout << "No accounts to display." << endl;
        return;
    }
    for(int i = 0; i < accountCount; i++) {
        accounts[i].display();
        cout << "-------------------------" << endl;
    }
}

// Main menu
int main() {
    // Pre-created account
    accounts[accountCount++] = BankAccount(1001, "Priya", 5000);

    int choice;
    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n";
        cout << "4. Display Account\n5. Display All Accounts\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: displayAllAccounts(); break;
            case 0: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }

    } while(choice != 0);

    return 0;
}
