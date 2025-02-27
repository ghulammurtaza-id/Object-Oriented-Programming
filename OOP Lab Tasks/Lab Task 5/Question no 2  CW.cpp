#include <bits/stdc++.h>
using namespace std;

class Book {
    long long isbn;
    string title;
public:
    Book(long long isbnNum, string bookTitle) {
        isbn = isbnNum;
        title = bookTitle;
    }
    long long getIsbn() {
        return isbn;
    }
    string getTitle() {
        return title;
    }
};

class Catalog {
    vector<long long> isbnList;
    vector<Book*> bookPointers;
public:
    void addToCatalog(Book* book) {
        isbnList.push_back(book->getIsbn());
        bookPointers.push_back(book);
    }
    Book* findBook(long long isbn) {
        for (int i = 0; i < isbnList.size(); i++) {
            if (isbnList[i] == isbn) {
                return bookPointers[i];
            }
        }
        return NULL;
    }
    void removeFromCatalog(long long isbn) {
        for (int i = 0; i < isbnList.size(); i++) {
            if (isbnList[i] == isbn) {
                isbnList.erase(isbnList.begin() + i);
                bookPointers.erase(bookPointers.begin() + i);
                return;
            }
        }
    }
};

class Library {
    Catalog catalog;
    vector<Book*> books;
public:
    void addBook(Book* book) {
        books.push_back(book);
        catalog.addToCatalog(book);
        cout << "Added book: " << book->getTitle() << endl;
    }
    void removeBook(long long isbn) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getIsbn() == isbn) {
                cout << "Removed book: " << books[i]->getTitle() << endl;
                books.erase(books.begin() + i);
                catalog.removeFromCatalog(isbn);
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found!" << endl;
    }
    void findBookInCatalog(long long isbn) {
        Book* foundBook = catalog.findBook(isbn);
        if (foundBook != NULL) {
            cout << "Found book: " << foundBook->getTitle() << " (ISBN: " << isbn << ")" << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in catalog!" << endl;
        }
    }
};

int main() {
    Book book1(123456789, "Rich and Grow");
    Book book2(987654321, "Independance of Hinds");
    Book book3(456789123, "1954 the biggest Masscare");
    Library myLibrary;
    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(&book3);

    myLibrary.findBookInCatalog(123456789);
    myLibrary.findBookInCatalog(111111111);

    myLibrary.removeBook(987654321);
    myLibrary.findBookInCatalog(987654321);

    return 0;
}