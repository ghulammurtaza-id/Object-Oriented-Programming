#include<bits/stdc++.h>
using namespace std;

class Circle{
	double radius;
	double PI =3.14;
	public :
		Circle(double Radius){
			radius = Radius;
		}
		double getArea(){
			return PI*radius*radius;
		}
		double getPerimeter(){
			return 2*PI*radius;
		}
};

int main(int argc, char **argv){
	double r = stod(argv[1]) * 1.00;
	Circle c1(r);
	cout<<"The Area is : "<< c1.getArea() << endl;
	cout<<"Ther perimeter is : "<< c1.getPerimeter() << endl;
}