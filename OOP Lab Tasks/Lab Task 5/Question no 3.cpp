#include <bits/stdc++.h>
using namespace std;


// task pdf me qno 6
struct Item {
    string name;
    string type;
    double price;
};

class CoffeeShop{
public:
    const string shopName;
    vector<Item>menu;
private:
    vector<string>orders;

public:
    CoffeeShop(string name, vector<Item> menu):shopName(name),menu(menu) {}

    string addOrder(const string& item){
        for (const auto& m : menu){
            if (m.name == item){
                orders.push_back(item);
                return "Order added";
            }
        }
        return "Unavailable";
    }

    string fulfillOrder(){
        if (!orders.empty()){
            string item = orders.front();
            orders.erase(orders.begin());
            return "Ready: " + item;
        }
        return "All fulfilled";
    }

    vector<string>listOrders()const {
        return orders;
    }

    double dueAmount() const{
        double total = 0.0;
        for (const auto& order : orders){
            for (const auto& m : menu) {
                if (m.name == order){
                    total += m.price;
                    break;
            }
            }
        }
        return total;
    }

    string cheapestItem()const{
        if (menu.empty())return "";
        auto minIt = min_element(menu.begin(),menu.end(),
            [](const Item& a,const Item& b) { return a.price <b.price; });
        return minIt->name;
    }

    vector<string> drinksOnly()const {
        vector<string> drinks;
        for (const auto& m : menu){
            if (m.type == "drink")drinks.push_back(m.name);
        }
        return drinks;
    }

    vector<string> foodOnly()const {
        vector<string>foods;
        for (const auto& m :menu){
            if (m.type == "food") foods.push_back(m.name);
        }
        return foods;
    }
};

int main() {
    vector<Item> menu = {{"Coffee", "drink", 2.5}
	, {"Tea", "drink", 2.0}, {"Sandwich", "food", 5.0},
	{"Cake", "food",3.5}};
    CoffeeShop shop("MyShop",menu);

    cout << shop.addOrder("Coffee")<< endl;
    cout << shop.addOrder("Burger") <<endl;
    cout << shop.fulfillOrder() <<endl;
    cout << "Due: $" <<shop.dueAmount() <<endl;
    cout << "Cheapest: " << shop.cheapestItem()<<endl;

    cout <<"Drinks: ";
    for (const auto& d :shop.drinksOnly()) 
	cout << d << " ";
    cout << "\nFood: ";
    for (const auto& f : shop.foodOnly()) 
	cout << f << " ";
    cout << endl;
    return 0;
}