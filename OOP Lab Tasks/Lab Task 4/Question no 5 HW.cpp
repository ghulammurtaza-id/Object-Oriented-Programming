#include<bits/stdc++.h>
using namespace std;

class MenuItem {
public:
    string name, type;
    double price;
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
    string name;
    MenuItem* menu;
    int menuSize;
    string* orders;
    int orderCount;

public:
    CoffeeShop(string n, MenuItem* m, int ms): name(n), menuSize(ms),orderCount(0) {
        menu = new MenuItem[ms];
        for (int i = 0; i < ms;i++) menu[i] =m[i];
        orders = new string[0];
    }

    ~CoffeeShop() {
        delete[] menu;
        delete[] orders;
    }

    string addOrder(string item) {
        for (int i= 0; i <menuSize; i++) {
            if (menu[i].name == item) {
                string* newOrders new string[orderCount + 1];
                for (int j = 0; j < orderCount; j++) newOrders[j] = orders[j];
                newOrders[orderCount] =item;
                delete[] orders;
                orders = newOrders;
                orderCount++;
                return "";
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderCount > 0) {
            string item =orders[0];
            string* newOrders = new string[orderCount - 1];
            for (int i = 1; i < orderCount; i++) newOrders[i - 1] = orders[i];
            delete[] orders;
        orders = newOrders;
        orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    void listOrders() {
        if (orderCount == 0) cout << "[]" << endl;
        else {
            cout << "[";
            for (int i = 0; i <orderCount; i++) {
                cout << orders[i] << (i < orderCount - 1 ? ", " : "");
            }
            cout << "]" << endl;
        }
    }

    double dueAmount() {
        double total = 0;
        for (int i = 0; i <orderCount; i++) {
            for (int j = 0; j <menuSize;j++) {
                if (orders[i] == menu[j].name) total += menu[j].price;
            }
        }
        return total;
    }

    string cheapestItem() {
        string cheapest =menu[0].name;
        double minPrice =menu[0].price;
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < minPrice) {
                minPrice =menu[i].price;
                cheapest =menu[i].name;
            }
        }
        return cheapest;
    }

    void drinksOnly() {
        for (int i = 0; i <menuSize; i++) {
            if (menu[i].type == "drink") cout << menu[i].name << " ";
        }
        cout << endl;
    }

    void foodOnly() {
        for (int i = 0; i <menuSize; i++) {
            if (menu[i].type == "food") cout << menu[i].name << " ";
        }
        cout << endl;
    }
};

int main(int argc, char **argv) {
    MenuItem menu[] = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Cake", "food", 3.0),
        MenuItem("Tea", "drink", 2.0)
    };
    CoffeeShop shop("MyCafe", menu, 3);
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Burger") << endl;
    shop.listOrders();
    cout << shop.fulfillOrder() << endl;
    cout << "Due: " << shop.dueAmount() << endl;
    cout << "Cheapest: " << shop.cheapestItem() << endl;
    shop.drinksOnly();
    shop.foodOnly();
    return 0;
}