#include <bits/stdc++.h>
using namespace std;

class Wallet {
private:
    double currentBalance;
    double todayDeposited;
    double todayWithdrawn;
    double maxDailyDeposit;
    double maxDailyWithdrawal;

public:
    Wallet(){}
    Wallet(double maxDailyDeposit, double maxDailyWithdrawal)
        : currentBalance(0), todayDeposited(0), todayWithdrawn(0),
          maxDailyDeposit(maxDailyDeposit), maxDailyWithdrawal(maxDailyWithdrawal) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            cout<<"Deposit must be more than zero"<<endl;
            return false;
        }
        if (todayDeposited + amount > maxDailyDeposit) {
            cout<<"You’ve reached your daily deposit limit"<<endl;
            return false;
        }
        currentBalance += amount;
        todayDeposited += amount;
        cout<<"Successfully added $" << amount <<". Current balance: $" << currentBalance <<endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout<<"Withdrawal must be more than zero"<<endl;
            return false;
        }
        if (amount > currentBalance) {
            cout<<"Not enough funds to withdraw $" << amount <<endl;
            return false;
        }
        if (todayWithdrawn + amount > maxDailyWithdrawal) {
            cout<<"You’ve reached your daily withdrawal limit"<<endl;
            return false;
        }
        currentBalance -= amount;
        todayWithdrawn += amount;
        cout<<"Successfully withdrew $" << amount <<". Current balance: $" << currentBalance <<endl;
        return true;
    }

    double getBalance() const {
        return currentBalance;
    }

    void resetLimits() {
        todayDeposited = 0;
        todayWithdrawn = 0;
    }
};

class User {
private:
    string userId;
    string fullName;
    Wallet userWallet;

public:
    User(string userId, string fullName) : userId(userId), fullName(fullName), userWallet(5000, 2000) {}

    bool deposit(double amount) {
        cout<<fullName<<": ";
        return userWallet.deposit(amount);
    }

    bool withdraw(double amount) {
        cout<<fullName<<": ";
        return userWallet.withdraw(amount);
    }

    void checkBalance() const {
        cout<<fullName<<": Your balance is $" << userWallet.getBalance() <<endl;
    }

    void resetLimits() {
        userWallet.resetLimits();
    }
};

int main() {
    User alice("U001", "Alice");
    User bob("U002", "Bob");
    alice.deposit(1000);
    alice.withdraw(300);
    alice.checkBalance();
    cout<<"\n";
    bob.deposit(6000);
    bob.deposit(4000);
    bob.deposit(2000);
    bob.withdraw(5000);
    bob.withdraw(1000);
    bob.checkBalance();
    cout<<"\nResetting limits for the new day...\n\n";
    alice.resetLimits();
    bob.resetLimits();
    bob.deposit(3000);
    bob.checkBalance();

    return 0;
}

