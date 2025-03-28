#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Polynomial {
private:
    vector<int> coeffs;

public:
    Polynomial() : coeffs(1, 0) {}

    Polynomial(const vector<int>& coefficients) : coeffs(coefficients) {
        trim();
    }

    Polynomial operator+(const Polynomial& other) const {
        int maxSize = max((int)coeffs.size(), (int)other.coeffs.size());
        vector<int> result(maxSize, 0);

        for (int i = 0; i < (int)coeffs.size(); i++) {
            result[i] += coeffs[i];
        }
        for (int i = 0; i < (int)other.coeffs.size(); i++) {
            result[i] += other.coeffs[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        int maxSize = max((int)coeffs.size(), (int)other.coeffs.size());
        vector<int> result(maxSize, 0);

        for (int i=0; i<(int)coeffs.size();i++) {
            result[i] += coeffs[i];
        }
        for (int i=0; i <(int)other.coeffs.size(); i++) {
            result[i] -=other.coeffs[i];
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result((int)coeffs.size() + (int)other.coeffs.size() - 1, 0);

        for (int i =0; i <(int)coeffs.size(); i++) {
            for (int j =0; j < (int)other.coeffs.size(); j++) {
                result[i+j] +=coeffs[i] *other.coeffs[j];
            }
        }
        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coeffs.empty() || (p.coeffs.size() == 1 && p.coeffs[0] == 0)) {
            return os<< "0";
        }

        bool first = true;
        for (int i = (int)p.coeffs.size()-1; i>= 0;i--) {
            if (p.coeffs[i]== 0) continue;
            if (!first && p.coeffs[i] >0) os << " + ";
            if (first && p.coeffs[i]<0) os << "-";
            else if (!first && p.coeffs[i] <0) os << " - ";
            int abs_coeff =abs(p.coeffs[i]);
            if (i== 0) {
                os << abs_coeff;
            } else if (i== 1) {
                if (abs_coeff==1) os << "x";
                else os <<abs_coeff << "x";
            } else {
                if (abs_coeff==1) os << "x^" << i;
                else os<<abs_coeff << "x^" << i;
            }
            first = false;
        }
        return os;
    }

    friend class PolynomialUtils;

private:
    void trim() {
        while (coeffs.size() > 1 && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p,int x) {
        int result =0;
        for(int i = (int)p.coeffs.size()-1; i>= 0; i--) {
            result =result *x+ p.coeffs[i];
        }
        return result;
    }

    static Polynomial derivative(const Polynomial& p){
        if (p.coeffs.size() <=1) return Polynomial();
        vector<int> result((int)p.coeffs.size() -1);




        for (int i =1; i <(int)p.coeffs.size();i++) {
            result[i -1] = p.coeffs[i] * i;
        }
        return Polynomial(result);
    }
};

int main() {
    Polynomial p1({1,2,3});  // 3x^2 + 2x + 1
    Polynomial p2({0,1,1});  // x^2 + x
    cout <<"p1: " << p1 << "\n";
    cout<< "p2: " << p2<< "\n";
    cout << "p1 + p2: " <<(p1 + p2) << "\n";
    cout<< "p1 - p2: " << (p1 -p2) << "\n";
    cout << "p1 * p2: " <<(p1 * p2)<< "\n";
    cout << "Evaluate p1 at x=2: "<< PolynomialUtils::evaluate(p1,2) << "\n";
    cout <<"Derivative of p1: " << PolynomialUtils::derivative(p1) <<"\n";

    return 0;
}