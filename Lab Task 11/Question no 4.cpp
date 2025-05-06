#include<bits/stdc++.h>
using namespace std;

template<typename T> class Base{ protected: T num1,num2; public: Base(T x,T y):num1(x),num2(y){} T getProduct(){return num1*num2;} };

template<typename T> class Derived:public Base<T>{ T val1,val2; public: Derived(T x,T y,T z,T w):Base<T>(x,y),val1(z),val2(w){} T calcDerived(){return val1*val2;} void displayAll(){ cout<<"Base Value:"<<this->getProduct()<<endl; cout<<"Derived Value:"<<calcDerived()<<endl; } };

int main(){ Derived<int>item(2,3,4,5); item.displayAll(); return 0; }
