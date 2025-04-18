#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    virtual void getdata()=0;
    virtual void display()=0;
    virtual void bonus()=0;
};

class Admin : virtual public Person {
protected:
    float adminSalary;
public:
    void getdata() override {
        cout<<"Enter admin salary:";
        cin>>adminSalary;
    }
    void display() override {
        cout<<"Admin Salary:"<<adminSalary<<endl;
    }
    void bonus() override {
        cout<<"Admin Bonus:"<<0.1 * adminSalary<<endl;
    }
};

class Account : virtual public Person {
protected:
    float accountBalance;
public:
    void getdata() override {
        cout<<"Enter account balance:";
        cin>>accountBalance;
    }
    void display() override {
        cout<<"Account Balance:"<<accountBalance<<endl;
    }
    void bonus() override {
        cout<<"Account Bonus:"<<0.05 * accountBalance<<endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Admin::getdata();
        Account::getdata();
    }
    void display() override {
        Admin::display();
        Account::display();
    }
    void bonus() override {
        Admin::bonus();
        Account::bonus();
        cout<<"Master Total Bonus:"<<0.1 * adminSalary + 0.05 * accountBalance<<endl;
    }
};

int main() {
    Person* personPtr;
    Master masterObj;
    personPtr = &masterObj;
    personPtr->getdata();
    personPtr->display();
    personPtr->bonus();
    return 0;
}

