#include<bits/stdc++.h>

using namespace std;

class Book {
private:
    string bookName;
    long long ISBN;
    string authorName;
    string publisher;

public:
    
    Book(const string& name, long long isbn, const string& author, const string& pub)
        : bookName(name), ISBN(isbn), authorName(author), publisher(pub) {}
    string getBookName() const { return bookName; }
    long long getISBN() const { return ISBN; }
    string getAuthorName() const { return authorName; }
    string getPublisher() const { return publisher; }
    string getBookInfo() const {
        return "Book: " + bookName + 
               "\nISBN: " + to_string(ISBN) +
               "\nAuthor: " + authorName + 
               "\nPublisher: " + publisher + "\n";
    }
};

int main() {
     Book books[] = {
        {"Algorithm Design Manual", 9783030542116LL, "Steven Skiena", "NEdians"},
        {"Competitive Programming 4", 9781716745522LL, "Steven Halim", "Independently"},
        {"Introduction to Algorithms", 9780262033848LL, "CLRS", "MIT Press"},
        {"CP Primer", 9783319725467LL, "Antti Laaksonen", "Selfs"},
        {"Advanced Algorithms", 9780999282942LL, "Jeff Erickson", "Fastians"}
    };
	//used iterator
    for (const auto& book : books) {
        cout << book.getBookInfo() << endl;
    }

    return 0;
}