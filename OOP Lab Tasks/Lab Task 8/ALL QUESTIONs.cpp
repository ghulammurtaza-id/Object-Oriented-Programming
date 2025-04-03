

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Task 1: Banking System Simulator
class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    
    
public:
    Account(string number, double initialBalance, string holderName){
        accountNumber = number;
        balance = initialBalance;
        
        
        
        
        accountHolderName = holderName;
    }
    void deposit(double amount){
        
        
        
        balance += amount;
    }
    virtual void withdraw(double amount) {
        

    if (amount <= balance) balance -= amount;
    }
    virtual double calculateInterest(){
        return 0.0;
        
        
    }
    virtual void printStatement() {
        cout << "Account: " << accountNumber <<" Balance: " << balance << endl;
    }
    string getAccountInfo() {
        return accountHolderName + " - " + accountNumber;
    }
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;
    
    
    
public:
    SavingsAccount(string number, double initialBalance, string holderName, double rate)
        : Account(number, initialBalance, holderName) {
        interestRate = rate;
        minimumBalance = 100.0;
        
        
        
    }
    double calculateInterest() {
        
        
        return balance * interestRate;
    }
    void withdraw(double amount) {
        if (balance - amount >= minimumBalance) balance -= amount;
        
    }
    void printStatement() {
        cout << "Savings - " << accountHolderName << ": $" << balance << endl;
        
    }
};

// Task 2: Geometric Shapes Design Tool
class Shape {
protected:
    double xPosition;
    double yPosition;
    string color;
    
    
public:
    Shape(double x, double y, string shapeColor) {
        xPosition = x;
        yPosition = y;
        color = shapeColor;
    }
    
    
    virtual void draw() {}
    virtual double calculateArea() { return 0.0; }
    virtual double calculatePerimeter() { return 0.0; }
};

class Circle : public Shape {
    double radius;
public:


    Circle(double x, double y, string shapeColor, double circleRadius)
        : Shape(x, y, shapeColor) {
        radius = circleRadius;
    }
    
    
    void draw() {
        cout << "Drawing circle at (" << xPosition << "," << yPosition << ")" << endl;
    }
    
    
    double calculateArea() {
        return 3.14 * radius * radius;
    }
    
    
    double calculatePerimeter() {
        return 2 * 3.14 * radius;
    }
};

// Task 3: Currency Converter
class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
public:
    Currency(double value,string code, string symbol,double rate) {
        amount = value;
        currencyCode = code;
        currencySymbol =symbol;
        exchangeRate = rate;
    }
    double convertToBase() {
        return amount *exchangeRate;
    }
    virtual void displayCurrency() {
        cout << currencySymbol <<amount << endl;
    }
    double convertTo(Currency& target) {
        
    
        double baseValue = convertToBase();
        return baseValue / target.exchangeRate;
    }
};

class Dollar : public Currency{
public:


    Dollar(double value) : Currency(value, "USD", "$", 1.0) {}
    void displayCurrency() {
        cout << "$" << amount << " USD" << endl;
    }
};

// Task 4: University Management System
class Person {
protected:

    string name;
    string id;
    string address;
    string phoneNumber;
    string email;
public:
    Person(string personName,string personId,string personAddress, string phone,string personEmail) {
        name = personName;
        id = personId;
        address = personAddress;
        phoneNumber = phone;
        email = personEmail;
        
        
    }
    virtual void displayInfo() {
        cout << name << " - " << id << endl;
    }
    void updateInfo(string newAddress, string newPhone) {
        address = newAddress;
        phoneNumber = newPhone;
        
        
        
    }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    double gpa;
    int enrollmentYear;
    

public:
    Student(string personName, string personId, string personAddress, string phone, string personEmail, int year)
        : Person(personName, personId, personAddress, phone, personEmail) {
        enrollmentYear = year;
        gpa = 0.0;
    }
    

    void displayInfo() {
        cout << "Student: " << name << " GPA: " << gpa << endl;
    }
};

// Task 5: Multimedia Library System
class Media {
protected:
    string title;
    string publicationDate;
    string uniqueId;
    
    
    string publisher;
    
    
public:
    Media(string mediaTitle,string date,string mediaId,string mediaPublisher) {
        title = mediaTitle;
        publicationDate = date;
        uniqueId = mediaId;
        publisher = mediaPublisher;
        
        
        
    }
    virtual void displayInfo(){
        cout << title << " - " << uniqueId << endl;
    }
    void checkOut() {
        cout << title << " checked out" << endl;
    }
    void returnItem() {
        cout << title << " returned" << endl;
    }
};

class Book : public Media {
    string author;
    string isbn;
    int numberOfPages;
public:
    Book(string mediaTitle,string date,string mediaId, string mediaPublisher,string bookAuthor, string bookIsbn, int pages)
        : Media(mediaTitle, date, mediaId, mediaPublisher) {
        author = bookAuthor;
        isbn = bookIsbn;
        numberOfPages = pages;
    }
    void displayInfo() {
        cout << "Book: " << title << "by " << author << endl;
    }
};

int main() {
    SavingsAccount savings("12345", 1000.0,"Monis", 0.05);
    savings.deposit(500.0);
    savings.printStatement();

    Circle circle(10.0, 20.0,"Red", 5.0);
    cout << "Area: " << circle.calculateArea() << endl;

    Dollar dollar(100.0);
    dollar.displayCurrency();

    Student student("Rahib Khan","S001", "123 Main St","555-1234","jane@email.com", 2023);
    student.displayInfo();

    Book book("C++ Guide","2023-01-01", "B001","Tech Press", "John Author","123-456-789", 300);
    book.displayInfo();

    return 0;
}