#include<bits/stdc++.h>
using namespace std;

class Books {
    string author,title, publisher;
    double price;
    int stock;

public:
    Books(string a, string t,string p,double pr,int s) 
        : author(a), title(t), publisher(p), price(pr), stock(s) {}

    bool isAvailable(string t, string a) {
        return (title == t && author == a);
    }

    void displayDetails() {
        cout << "Title: " <<title << ", Author: " << author 
             << ", Publisher: " << publisher<< ", Price: " << price 
             << ", Stock: " << stock << endl;
    }

    void processSale(int copies) {
        if (stock >=copies) {
            stock -=copies;
            cout << "Total Cost: " << copies * price << endl;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main(int argc, char **argv) {
    Books inventory[] = {
        Books("Author1", "Book1", "Pub1", 20.5, 10),
        Books("Author2", "Book2", "Pub2", 15.0, 5)
    };
    int n = 2;
    string title, author;
    cout << "Enter title: "; getline(cin, title);
    cout << "Enter author: "; getline(cin, author);
    bool found = false;
    for (int i =0; i <n; i++){
        if(inventory[i].isAvailable(title, author)) {
            found = true;
            inventory[i].displayDetails();
            int copies;
            cout << "Enter number of copies: "; cin >> copies;
            inventory[i].processSale(copies);
            break;
        }
    }
    if (!found) cout << "Book not available" << endl;
    return 0;
}