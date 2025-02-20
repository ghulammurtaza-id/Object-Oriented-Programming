#include<bits/stdc++.h>
using namespace std;

class Account{
    double balance;

public:
    Account() {
        balance = 0; 
    }
    void credit(double amount){
        if (amount >0) balance += amount; 
    }
    void debits(double amount){
        if (amount > 0 &&balance>= amount) balance -= amount; 
    }
    double getBalance(){ 
        return balance;
    }
};

int main(int argc, char **argv){
    Account fast;
    fast.credit(5000);
    fast.debits(200);
    cout << fast.getBalance() << endl;
    return 0;
}