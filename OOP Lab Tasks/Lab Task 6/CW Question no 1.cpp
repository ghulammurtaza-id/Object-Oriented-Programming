#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
protected:
   string accountNumber;
    double balance;
public:
    BankAccount(string num, double bal): accountNumber(num),balance(bal){}
    virtual void deposit(double amount){
        balance += amount;
        cout << "Deposited " << amount << " to "<< accountNumber<< ". New balance: "<< balance << endl;
    }
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from " << accountNumber << ". New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance in " << accountNumber << endl;
        }
    }
    virtual void specialOperation() = 0;
};

class SavingsAccount : public BankAccount {
    double interestRate = 0.05;
public:
    SavingsAccount(string num, double bal): BankAccount(num, bal){}
    void specialOperation() override{
        double interest = balance *interestRate;
        balance +=interest;
        cout << "Interest of " << interest << " added to " << accountNumber << ". New balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit = 500;
public:
    CheckingAccount(string num, double bal) : BankAccount(num, bal) {}
    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn " <<amount<< " from " <<accountNumber<< ". New balance: " <<balance << endl;
            if (balance < 0) cout << "Overdraft alert for " <<accountNumber << endl;
        } else {
            cout << "Overdraft limit exceeded in " << accountNumber << endl;
        }
    }
    void specialOperation() override {}
};

class BusinessAccount : public BankAccount {
    double taxRate = 0.10;
public:
    BusinessAccount(string num, double bal): BankAccount(num, bal) {}
    void deposit(double amount) override {
        double tax = amount * taxRate;
        balance += (amount - tax);
        cout << "Deposited " << amount << " to " << accountNumber << ", tax withheld: " << tax << ". New balance: " << balance << endl;
    }
    void specialOperation()override {}
};

class UserRole {
public:
    virtual void performAction(BankAccount* account, double amount) = 0;
};

class Customer : public UserRole {
public:
    void performAction(BankAccount* account, double amount)override {
        account->deposit(amount);
    }
};

class Teller: public UserRole{
public:
    void performAction(BankAccount* account, double amount) override {
        account->withdraw(amount);
    }
};

class Manager : public Teller {
public:
    void performAction(BankAccount* account, double amount) override {
        account->specialOperation();
    }
};

int main() {
    vector<BankAccount*> accounts;
    accounts.push_back(new SavingsAccount("SA001", 1000));
    accounts.push_back(new CheckingAccount("CA001",500));
    accounts.push_back(new BusinessAccount("BA001", 2000));

    vector<UserRole*> roles;
    roles.push_back(new Customer());
    roles.push_back(new Teller());
    roles.push_back(new Manager());

    for (auto account: accounts) {
        account->deposit(200);
        account->withdraw(300);
        account->specialOperation();
    }

    for (auto role : roles) {
        role->performAction(accounts[0], 100);
    }

    return 0;
}
