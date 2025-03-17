#include <iostream>
#include <string>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) :genre(g){}
};

class Novel :public Books {
    string title;
    string author;
public:
    Novel(string g, string t, string a):Books(g),title(t),author(a) {}
    void display() {
        cout << "Genre: "<<genre <<", Title: " <<title <<", Author: " <<author <<endl;
    }
};

class Mystery :public Books {
    string title;
    string author;
public:
    Mystery(string g, string t, string a):Books(g), title(t), author(a){}
    void display() {
        cout << "Genre: " <<genre <<", Title: " <<title<< ", Author: :: " <<author<< endl;
    }
};

int main() {
    Novel book1("Novel", "Pakistan J", "DOllar trump");
    Mystery book2("Mystery", "youth D", "Imran KhaN");

    book1.display();
    book2.display();

    return 0;
}
