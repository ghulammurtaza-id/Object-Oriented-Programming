#include <bits/stdc++.h>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    virtual void setPrice(float basePrice) = 0;
    string getModel() {
        return model;
    }
    float getPrice() {
        return price;
    }
    void setModel(string modelName) {
        model = modelName;
    }
};

class Color : public Car {
    string carColor;
public:
    void setColor(string colorName) {
        carColor = colorName;
    }
    string getColor() {
        return carColor;
    }
    void setPrice(float basePrice) override {
        price = basePrice + 1000;
    }
};

class Company : public Car {
    string carCompany;
public:
    void setCompany(string companyName) {
        carCompany = companyName;
    }
    string getCompany() {
        return carCompany;
    }
    void setPrice(float basePrice) override {
        price = basePrice + 2000;
    }
};

int main() {
    Color colorCar;
    colorCar.setModel("X");
    colorCar.setColor("Red");
    colorCar.setPrice(30000);

    Company companyCar;
    companyCar.setModel("Y");
    companyCar.setCompany("Tesla");
    companyCar.setPrice(35000);

    cout<<"Color Car - Model:"<<colorCar.getModel()<<", Color:"<<colorCar.getColor()<<", Price:"<<colorCar.getPrice()<<endl;
    cout<<"Company Car - Model:"<<companyCar.getModel()<<", Company:"<<companyCar.getCompany()<<", Price:"<<companyCar.getPrice()<<endl;

    return 0;
}

