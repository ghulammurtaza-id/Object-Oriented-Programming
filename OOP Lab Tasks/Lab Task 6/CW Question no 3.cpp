#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Employee {
protected:
    string id;
    string name;
public:
    Employee(string i,string n) : id(i),name(n) {}
};

class IOrderTaker{
public:
    virtual void takeOrder() = 0;
};

class IOrderPreparer{
public:
    virtual void prepareOrder() =0;
};

class IBiller {
public:
    virtual void generateBill() =0;
};

class Waiter :public Employee, public IOrderTaker{
public:
    Waiter(string i, string n) :Employee(i, n) {}
    void takeOrder() override {
        cout << name << " is taking an order."<< endl;
    }
};

class Chef : public Employee,public IOrderPreparer{
public:
    Chef(string i, string n) : Employee(i, n) {}
    void prepareOrder() override {
        cout << name << " is preparing an order." << endl;
    }
};

class Cashier :public Employee,public IBiller {
public:
    Cashier(string i, string n) :Employee(i, n){}
    void generateBill() override {
        cout << name << " is generating a bill." << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(string i, string n): Employee(i, n) {}
    void takeOrder() override {
        cout << name << " (Manager is taking an order." << endl;
    }
    void generateBill() override {
        cout << name << " (Manager is generating a bill." << endl;
    }
};

class Menu {
protected:
    string name;
    double price;
public:
    Menu(string n, double p) : name(n), price(p) {}
    virtual double calculateCost() = 0;
};

class FoodMenu : public Menu {
public:
    FoodMenu(string n, double p) : Menu(n, p) {}
    double calculateCost() override {
        return price;
    }
};

class BeverageMenu : public Menu {
    double tax = 0.15;
public:
    BeverageMenu(string n, double p) : Menu(n, p) {}
    double calculateCost() override {
        return price + (price * tax);
    }
};

int main() {
    vector<Employee*> employees;
    employees.push_back(new Waiter("W001", "Ali"));
    employees.push_back(new Chef("C001","Ahmed"));
    employees.push_back(new Cashier("CA001", "Bilal"));
    employees.push_back(new Manager("M001","Kamran"));

    vector<IOrderTaker*> takers;
    takers.push_back(new Waiter("W002","Usman"));
    takers.push_back(new Manager("M002","Faisal"));

    for (auto taker : takers){
        taker->takeOrder();
    }

    vector<Menu*> menus;
    menus.push_back(new FoodMenu("Biryani",200));
    menus.push_back(new BeverageMenu("Cola", 50));

    for (auto menu : menus) {
        cout << "Cost: " << menu->calculateCost() << endl;
    }

    return 0;
}
