#include<bits/stdc++.h>
using namespace std;
class Shape {
private:
    double area;
public:
    Shape(double a = 0):area(a){}
    double Area() const{
        return area;
    }
    Shape operator+(const Shape& other)const{
        return Shape(area +other.area);
    }
    friend ostream& operator<<(ostream& os,const Shape& s){
        os << s.area;
        return os;
    }
};

int main() {
    Shape shape1(25.5);
    Shape shape2(74.5);
    cout << "Area of shape1: "<<shape1 << endl;
    cout << "Area of shape2: " <<shape2 <<endl;

    Shape combined=shape1 + shape2;
    cout << "Combined area shape1 + shape2): " <<combined<< endl;
    cout << "Using Area method on combined: " << combined.Area() <<endl;

    return 0;
}