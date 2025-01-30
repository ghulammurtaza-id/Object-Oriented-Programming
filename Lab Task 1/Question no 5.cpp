#include<bits/stdc++.h>
using namespace std;

int main(){
	int adultticket;
	int childticket;
	float aprize;
	float cprize;
	float pdonate;
	cout<<"Please Enter the Movie Name : " << endl;
	string s;
	getline(cin,s);
	cout<<"Adult ticket Price: ";
	cin>>aprize;
	cout<<"Child ticket Price: ";
	cin>>cprize;
	cout<<"Sold Adult Number of ticket: ";
	cin>>adultticket;
	cout<<"Sold Child Number of ticket: ";
	cin>>childticket;
	cout<<"Prcentage of the gross amount to bedonated to the charity. i.e 10,20"<< endl;
	cin>>pdonate;
	float p = pdonate;
	
	pdonate/=100;
	cout<<fixed<<setprecision(2)<< endl;
	cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
	cout<<"Movie Name: ...................................."<<s<<endl;
	cout<< "Number of Tickets Sold .......................... "<<adultticket+childticket<<endl;
	float gross = aprize*adultticket+cprize*childticket;
	cout<<"Gross Amount: ......................................... $" <<gross<<endl;
	cout<<"Percentage of Gross Amount Donated: .................."<<p<<"%"<< endl;
	float donate = pdonate*gross;
	cout<< "Amount Donated: ................................... $"<<donate<<endl;
	cout<< "Net Sale: ................................................... $" <<gross - donate<< endl;
	
	
	
	return 0;
}