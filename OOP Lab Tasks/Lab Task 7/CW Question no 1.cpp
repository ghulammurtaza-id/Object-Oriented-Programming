
#include<bits/stdc++.h>
using namespace std;

class Fraction {
    int nominator, denominator;
    int GCD(int a, int b) {
        if(b == 0)
            return abs(a);
        return GCD(b, a % b);
    }
    void reduce() {
        int gcd = GCD(abs(nominator), abs(denominator));
        nominator = nominator / gcd;
        denominator = denominator / gcd;
        if(denominator < 0) {
            nominator = -nominator;
            denominator = -denominator;
        }
    }
public:
    Fraction(int n, int d) {
        if(d == 0)
            throw runtime_error("Denominator cannot be zero");
        nominator = n;
        denominator = d;
        reduce();
    }
   
    Fraction operator+(const Fraction& f2) {
        return Fraction(nominator * f2.denominator + denominator * f2.nominator,
                       denominator * f2.denominator);
    }
   
    Fraction operator-(const Fraction& f2) {
        return Fraction(nominator * f2.denominator - denominator * f2.nominator,
                       denominator * f2.denominator);
    }
   
    Fraction operator*(const Fraction& f2) {
        return Fraction(nominator * f2.nominator,
                       denominator * f2.denominator);
    }
   
    Fraction operator/(const Fraction& f2) {
        if(f2.nominator == 0)
            throw runtime_error("Division by zero");
        return Fraction(nominator * f2.denominator,
                       denominator * f2.nominator);
    }
   
    bool operator==(const Fraction& f2) {
        return (nominator * f2.denominator) == (f2.nominator * denominator);
    }
   
    bool operator!=(const Fraction& f2) {
        return !(*this == f2);
    }
   
    bool operator<(const Fraction& f2) {
        return (nominator * f2.denominator) < (f2.nominator * denominator);
    }
   
    bool operator>(const Fraction& f2) {
        return (nominator * f2.denominator) > (f2.nominator * denominator);
    }
   
    bool operator<=(const Fraction& f2) {
        return !(*this > f2);
    }
   
    bool operator>=(const Fraction& f2) {
        return !(*this < f2);
    }
   
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if(f.denominator == 1)
            os << f.nominator;
        else
            os << f.nominator << "/" << f.denominator;
        return os;
    }
   
    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        int n, d = 1;
        char c;
        is >> n;
        if(is.peek() == '/') {
            is >> c >> d;
        }
        f = Fraction(n, d);
        return is;
    }
};

int main() {
    Fraction f1(2, 4);
    Fraction f2(3, 6);
    cout << (f1 + f2) << endl;
   
    Fraction f3(1, 2);
    Fraction f4(1, 2);
    cout << (f3 == f4) << endl;
   
    return 0;
}
