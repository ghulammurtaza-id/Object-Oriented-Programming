#include<bits/stdc++.h>

using namespace std;
class Number {
private:
    double value;

public:
    Number(double v = 0) :value(v){}
    Number& operator--(){
        value *= 4;
        return *this;
    }
    Number operator--(int){
        Number temp = *this;
        value /=4;
        return temp;
    }
    friend ostream& operator<<(ostream& os,const Number& n){
        os << n.value;
        return os;
    }
};
int main() {
    Number n1(8.0);
    cout << "Original value"<< n1<< endl;

    --n1;
    cout << "After prefix -- (multiply by 4): "<< n1<< endl;

    Number n2 = n1--; 
    cout <<"Returned value from postfix --: "<< n2 << endl;
    cout << "Current value after postfix -- divide by 4: "<< n1<<endl;

    return 0;
}