#include<bits/stdc++.h>
using namespace std;

class Polynomial {
    double* coeff;
    int degree;

public:
    // default constr auto call if the user put no parimeterrr.
    Polynomial(): degree(0){
        coeff = new double[1];
        coeff[0] = 0;
    }

    //
	//when two parameter passed ,parameterized constructor
    Polynomial(int deg, double* coefficients) : degree(deg) {
        coeff = new double[deg + 1];
        for (int i = 0; i <= deg; i++) {
            coeff[i] = coefficients[i];
        }
    }

    // simple ccopy constructor
    Polynomial(const Polynomial& other) :degree(other.degree){
        coeff = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coeff[i] = other.coeff[i];
        }
    }

    // constr for move 
    Polynomial(Polynomial&& other) :degree(other.degree), coeff(other.coeff){
        other.degree = 0;
        other.coeff = nullptr;
    }

   
    ~Polynomial() {
        delete[] coeff;
    }

    int getDegree() const { return degree; }

    double evaluate(double x) const{
        double result = 0;
        for (int i = degree; i >= 0; i--){
            result = result * x + coeff[i];
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const{
        int maxDegree = max(degree, other.degree);
        double* newCoeff = new double[maxDegree + 1];
        for (int i = 0; i <= maxDegree; i++) {
            double a = (i<= degree) ? coeff[i] : 0;
            double b = (i <= other.degree) ? other.coeff[i] : 0;
            newCoeff[i] = a + b;
        }
        return Polynomial(maxDegree, newCoeff);
    }

    Polynomial multiply(const Polynomial& other) const{
        int newDegree = degree + other.degree;
        double* newCoeff = new double[newDegree+1];
        for (int i =0; i <=newDegree; i++) newCoeff[i] = 0;
        	for(int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                newCoeff[i + j] += coeff[i] * other.coeff[j];
            }
        }
        return Polynomial(newDegree, newCoeff);
    }
};

int main(int argc, char **argv) {
    double c1[] = {1,2,3}; 
    Polynomial p1(2,c1);
    double c2[] = {2,1};    
    Polynomial p2(1,c2);
    Polynomial sum = p1.add(p2);
    Polynomial prod = p1.multiply(p2);
    cout << "Eval at x=2: " << p1.evaluate(2) << endl;
    return 0;
}