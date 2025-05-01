#include <bits/stdc++.h>

using namespace std;

class Customer{
public:
    string customerId;
    string fname;
    string lname;
    string emailAddress;
    Customer(string id,string first,string last,string email):customerId(id),fname(first),lname(last),emailAddress(email){}
};

class Item{
public:
    string itemId;
    string itemName;
    string itemDesc;
    int cost;
    Item(string id,string name,string desc,int price):itemId(id),itemName(name),itemDesc(desc),cost(price){}
};

class Purchase{
public:
    string customerId;
    string itemId;
    int amountPaid;
    Purchase(string custId,string prodId,int amount):customerId(custId),itemId(prodId),amountPaid(amount){}
};

void createCustomerTable(vector<Customer>& customers){
    customers.push_back(Customer("U001","Yusuf","Khan","yusuf@tech.com"));
    customers.push_back(Customer("U002","Ayesha","Malik","ayesha@history.com"));
    ofstream customerFile("customers.txt");
    for(int i=0;i<customers.size();i++){
        customerFile<<customers[i].customerId<<" "<<customers[i].fname<<" "<<customers[i].lname<<" "<<customers[i].emailAddress<<"\n";
    }
    customerFile.close();
}

void createItemTable(vector<Item>& items){
    items.push_back(Item("P001","Laptop","Gaming Laptop",1200));
    items.push_back(Item("P002","Mouse","Wireless Mouse",50));
    items.push_back(Item("P003","Keyboard","Mechanical Keyboard",100));
    ofstream itemFile("items.txt");
    for(int i=0;i<items.size();i++){
        itemFile<<items[i].itemId<<" "<<items[i].itemName<<" "<<items[i].itemDesc<<" "<<items[i].cost<<"\n";
    }
    itemFile.close();
}

void createPurchaseTable(vector<Purchase>& purchases){
    purchases.push_back(Purchase("U001","P001",1200));
    purchases.push_back(Purchase("U001","P002",50));
    purchases.push_back(Purchase("U002","P003",100));
    ofstream purchaseFile("purchases.txt");
    for(int i=0;i<purchases.size();i++){
        purchaseFile<<purchases[i].customerId<<" "<<purchases[i].itemId<<" "<<purchases[i].amountPaid<<"\n";
    }
    purchaseFile.close();
}

void queryItemsForYusuf(){
    vector<Customer> customers;
    vector<Item> items;
    vector<Purchase> purchases;

    ifstream customerFile("customers.txt");
    string line;
    while(getline(customerFile,line)){
        stringstream ss(line);
        string id,first,last,email;
        ss>>id>>first>>last>>email;
        customers.push_back(Customer(id,first,last,email));
    }
    customerFile.close();

    ifstream itemFile("items.txt");
    while(getline(itemFile,line)){
        stringstream ss(line);
        string id,name,desc;
        int price;
        ss>>id>>name>>desc>>price;
        items.push_back(Item(id,name,desc,price));
    }
    itemFile.close();

    ifstream purchaseFile("purchases.txt");
    while(getline(purchaseFile,line)){
        stringstream ss(line);
        string custId,prodId;
        int amount;
        ss>>custId>>prodId>>amount;
        purchases.push_back(Purchase(custId,prodId,amount));
    }
    purchaseFile.close();

    string targetCustomerId;
    for(int i=0;i<customers.size();i++){
        if(customers[i].fname=="Yusuf"){
            targetCustomerId=customers[i].customerId;
            break;
        }
    }

    cout<<"Items purchased by Yusuf:\n";
    for(int i=0;i<purchases.size();i++){
        if(purchases[i].customerId==targetCustomerId){
            for(int j=0;j<items.size();j++){
                if(items[j].itemId==purchases[i].itemId){
                    cout<<items[j].itemName<<"\n";
                }
            }
        }
    }
}

int main(){
    vector<Customer> customers;
    vector<Item> items;
    vector<Purchase> purchases;

    createCustomerTable(customers);
    createItemTable(items);
    createPurchaseTable(purchases);
    queryItemsForYusuf();

    return 0;
}
