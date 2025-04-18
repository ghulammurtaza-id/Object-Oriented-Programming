#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape {
    float width, height;
public:
    Rectangle(float width, float height) : width(width), height(height) {}
    float getArea() override {
        return width * height;
    }
};

class Triangle : public Shape {
    float base, height;
public:
    Triangle(float base, float height) : base(base), height(height) {}
    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* rectangle = new Rectangle(4, 5);
    Shape* triangle = new Triangle(3, 6);

    cout<<"Area of Rectangle:"<<rectangle->getArea()<<endl;
    cout<<"Area of Triangle:"<<triangle->getArea()<<endl;

    delete rectangle;
    delete triangle;
    return 0;
}

