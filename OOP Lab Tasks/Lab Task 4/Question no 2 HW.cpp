#include<bits/stdc++.h>
using namespace std;

class Account{
	double balance;

	public :
		void credit(double amount){
			balance +=amount;
		}
		void debits(double amount ){
			balance -=amount ;
		}
		double getbalance(){
			return balance;
		}
};

int main(int argc, char **argv){
	Account fast;
	fast.credit(5000);
	fast.debits(200);
	cout<<fast.getbalance();
}S