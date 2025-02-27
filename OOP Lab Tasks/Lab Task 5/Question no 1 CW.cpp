#include <bits/stdc++.h>
using namespace std;

class Engine {
    bool isRunning;
public:
    void start() {
        isRunning = 1;
        cout << "Car Started" << endl;
    }
    void stop() {
        isRunning = 0;
        cout << "Car Stoped" << endl; 
    }
};

class Car {
    int id;
    Engine engine;
public:
    int getid() {
        return id;
    }
    void setid(int id) {
        this->id = id;
    }
    void startCar() {
        engine.start();
    }
    void stopCar() {
        engine.stop();
    }
};

class Garage {
    vector<Car*> cars;
public:
    Garage() {}
    ~Garage() {
        for (int i = 0; i < cars.size(); i++) {
            delete cars[i];
        }
        cars.clear();
    }
    void parkCar(Car* car) {
        cars.push_back(car);
    }
    void listCar() {
        for (int i = 0; i < cars.size(); i++) {
            cout << cars[i]->getid() << endl;
        }
    }
};

int main() {
    Car c1, c2, c3;
    c1.setid(1001);
    c2.setid(1002);
    c3.setid(1003);

    c1.startCar();
    c1.stopCar();
    Garage g1;
    g1.parkCar(&c1);
    g1.parkCar(&c2);
    g1.parkCar(&c3);

    g1.listCar();
    return 0;
}