#include <iostream>
#include <string>
using namespace std;
class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) :price(p) {}
};

class Car :public Vehicles {
protected:
    int seatingCapacity;
    int doors;
    string fuelType;
public:
    Car(double p, int s,int d, string f) :Vehicles(p), seatingCapacity(s),doors(d),fuelType(f) {}
};

class Motorcycle :public Vehicles {
protected:
    int cylinders;
    int gears;
    int wheels;
public:
    Motorcycle(double p, int c, int g, int w) :Vehicles(p), cylinders(c),gears(g), wheels(w) {}
};

class Audi : public Car {
    string modelType;
public:
    Audi(double p, int s, int d, string f, string m) : Car(p, s, d, f), modelType(m) {}
    void display() {
        cout << "Audi - Price: " << price << ", Seating: "<< seatingCapacity << ", Doors: " <<doors 
             << ", Fuel: " << fuelType << ", Model: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
    string makeType;
public:
    Yamaha(double p, int c, int g, int w, string m):Motorcycle(p, c, g, w), makeType(m) {}
    void display() {
        cout << "Yamaha - Price: " << price << ", Cylinders: " << cylinders << ", Gears: " << gears 
             << ", Wheels: " << wheels << ", Make: " << makeType << endl;
    }
};

int main() {
    Audi car(410000, 5, 4, "Petrol", "A4");
    Yamaha bike(150000, 2, 6, 2, "R1");
    car.display();
    bike.display();

    return 0;
}
