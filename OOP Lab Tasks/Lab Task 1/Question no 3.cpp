#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int id;
    string name;
    float unitc;
    float amountcharges = 0; 
    float surcharges = 0;
    float net = 0;

    cin >> id;
    cin >> name;
    cin >> unitc;

    float rs; 
	if (unitc <= 199) {
        rs = 16.20;
        amountcharges = unitc *rs;
    } else if (unitc >= 200 && unitc <= 299) {
        rs = 20.10;
        amountcharges = unitc* rs;
    } else if (unitc >= 300 && unitc <= 499) {
        rs = 27.10;
        amountcharges = unitc * rs;
    } else if (unitc >= 500) {
        rs = 35.90;
        amountcharges = unitc*rs;
    }

   if (amountcharges > 18000) {
        surcharges = amountcharges * 0.15; 
    }
    net = amountcharges + surcharges;  
	cout << "Customer ID: " << id << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << unitc << endl;
    cout << "Amount Charges @Rs. " << fixed << setprecision(2) << rs 
         << " per unit: " << fixed << setprecision(2) << amountcharges << endl;
    cout << "Surcharge Amount: " << fixed << setprecision(2) << surcharges << endl;
    cout << "Net Amount Paid by the Customer: " << fixed << setprecision(2) << net << endl;

    return 0;
}
